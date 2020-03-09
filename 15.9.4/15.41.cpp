#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "TextQuery.h"

using std::allocator;
using std::array;
using std::back_inserter;
using std::begin;
using std::cerr;
using std::cin;
using std::copy;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::find;
using std::forward_list;
using std::front_inserter;
using std::getline;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::make_shared;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::runtime_error;
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::stringstream;
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using namespace std::placeholders;

class BaseQuery {
    friend class Query;

    virtual QueryResult eval(const TextQuery& tq) const = 0;
    virtual string rep() const = 0;

   protected:
    virtual ~BaseQuery() = default;
};

class WordQuery : public BaseQuery {
    friend class Query;
    string word;

    WordQuery(const string& word) : word(word) {}

    virtual QueryResult eval(const TextQuery& tq) const override {
        return tq.query(word);
    }
    virtual string rep() const override {
        return word;
    }
};

class Query {
    friend Query operator~(const Query& wq);
    friend Query operator&(const Query& l, const Query& r);
    friend Query operator|(const Query& l, const Query& r);

    // shared_ptr<BaseQuery> bq;

    BaseQuery* bq;
    size_t* ptr_count;

    Query(BaseQuery* bq) : bq(bq), ptr_count(new size_t(1)) {}

   public:
    Query(const string& word) : bq(new WordQuery(word)), ptr_count(new size_t(1)) {}
    Query(const Query& ori) : bq(ori.bq), ptr_count(ori.ptr_count) {
        ++*ptr_count;
    }
    Query& operator==(const Query& cp) {
        ++*cp.ptr_count;
        if (--*ptr_count == 0) {
            delete bq;
            delete ptr_count;
        }
        bq = cp.bq;
        ptr_count = cp.ptr_count;
        return *this;
    }

    ~Query() {
        if (--*ptr_count == 0) {
            delete bq;
            delete ptr_count;
        }
    }

    QueryResult eval(const TextQuery& tq) const { return bq->eval(tq); }
    string rep() const { return bq->rep(); }
};

class NotQuery : public BaseQuery {
    friend Query operator~(const Query& wq);
    Query wq;

    NotQuery(const Query& wq) : wq(wq) {}
    virtual QueryResult eval(const TextQuery& tq) const override {
        auto rs = wq.eval(tq);
        size_t line_num = rs.get_lines()->size();
        shared_ptr<set<int>> idx = make_shared<set<int>>();

        auto skip_idx = rs.get_idx();
        for (int i = 0; i < line_num; i++) {
            if (skip_idx->find(i) == skip_idx->end()) idx->insert(i);
        }

        return QueryResult(idx, rs.get_lines());
    }
    virtual string rep() const override {
        return "~" + wq.rep();
    }
};

class BinaryQuery : public BaseQuery {
    string sign;

   protected:
    Query l, r;
    BinaryQuery(const Query& l, const Query& r, const string& sign) : l(l), r(r), sign(sign) {}

    virtual string rep() const override {
        return "(" + l.rep() + " " + sign + " " + r.rep() + ")";
    }
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query& l, const Query& r);

    AndQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "&") {}

    virtual QueryResult eval(const TextQuery& tq) const override {
        auto lrs = l.eval(tq), rrs = r.eval(tq);
        auto lidx = lrs.get_idx(), ridx = rrs.get_idx();

        shared_ptr<set<int>> idx = make_shared<set<int>>();
        std::set_intersection(lidx->begin(), lidx->end(), ridx->begin(), ridx->end(), inserter(*idx, idx->begin()));
        return QueryResult(idx, lrs.get_lines());
    }
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query& l, const Query& r);

    OrQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "|") {}

    virtual QueryResult eval(const TextQuery& tq) const override {
        auto lrs = l.eval(tq), rrs = r.eval(tq);
        auto lidx = lrs.get_idx(), ridx = rrs.get_idx();

        shared_ptr<set<int>> idx = make_shared<set<int>>();
        std::set_union(lidx->begin(), lidx->end(), ridx->begin(), ridx->end(), inserter(*idx, idx->begin()));
        return QueryResult(idx, lrs.get_lines());
    }
};

Query operator~(const Query& wq) {
    return new NotQuery(wq);
}

Query operator&(const Query& l, const Query& r) {
    return new AndQuery(l, r);
}

Query operator|(const Query& l, const Query& r) {
    return new OrQuery(l, r);
}

ostream& operator<<(ostream& os, const Query& query) {
    os << query.rep();
    return os;
}

void test1() {
    ifstream ifs("story.txt");
    TextQuery tq(ifs);

    Query q("bird");
    cout << (q) << endl;
    q.eval(tq).print();

    cout << ("=====") << endl;

    Query nq = ~q;
    cout << (nq) << endl;
    nq.eval(tq).print();

    cout << ("=====") << endl;

    Query q2("beautiful");
    Query andq = q & q2;
    cout << (andq) << endl;
    andq.eval(tq).print();

    cout << ("=====") << endl;
    Query q3("hair");
    cout << (q3) << endl;
    q3.eval(tq).print();

    Query orq = q | q3;
    cout << (orq) << endl;
    orq.eval(tq).print();

    Query q4("a");
    Query comq = orq & q4;
    cout << (comq) << endl;
    comq.eval(tq).print();
}

int main(int argc, char** argv) {
    test1();
    // Query q("a");
    // cout << (q) << endl;

    // Query nq = ~Query("a");
    // cout << (nq) << endl;

    // Query andq = Query("a") & Query("b");
    // cout << (andq) << endl;

    // Query orq = Query("a") | Query("b");
    // cout << (orq) << endl;

    // Query comq = andq & orq;
    // cout << (comq) << endl;
}