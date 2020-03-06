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

/**
 * 反思:1. 继承体系里的父类要定义virtual的析构函数
 **/

class BaseQuery {
    friend class Query;

   public:
    virtual ~BaseQuery() = default;

    virtual QueryResult eval(const TextQuery& tq) const = 0;
    virtual string rep() const = 0;
};

class WordQuery : public BaseQuery {
    string word;

   public:
    WordQuery(string s) : word(s) {}

    QueryResult eval(const TextQuery& tq) const override {
        return tq.query(word);
    }

    string rep() const override {
        return word;
    }
};

class NotQuery : public BaseQuery {
    shared_ptr<BaseQuery> bq;

   public:
    NotQuery(shared_ptr<BaseQuery> bq) : bq(bq) {}

    QueryResult eval(const TextQuery& tq) const override {
        auto rs = bq->eval(tq);
        size_t line_num = rs.get_lines()->size();
        shared_ptr<set<int>> idx = make_shared<set<int>>();

        auto skip_idx = rs.get_idx();
        for (int i = 0; i < line_num; i++) {
            if (skip_idx->find(i) == skip_idx->end()) idx->insert(i);
        }

        return QueryResult(idx, rs.get_lines());
    }

    string rep() const override {
        return "~" + bq->rep();
    }
};

class BinaryQuery : public BaseQuery {
   protected:
    shared_ptr<BaseQuery> l;
    shared_ptr<BaseQuery> r;

   public:
    BinaryQuery(shared_ptr<BaseQuery> l, shared_ptr<BaseQuery> r) : l(l), r(r) {}
};

class AndQuery : public BinaryQuery {
   public:
    AndQuery(shared_ptr<BaseQuery> l, shared_ptr<BaseQuery> r) : BinaryQuery(l, r) {}

    QueryResult eval(const TextQuery& tq) const override {
        auto lrs = l->eval(tq), rrs = r->eval(tq);
        auto lidx = lrs.get_idx(), ridx = rrs.get_idx();

        shared_ptr<set<int>> idx = make_shared<set<int>>();
        std::set_intersection(lidx->begin(), lidx->end(), ridx->begin(), ridx->end(), inserter(*idx, idx->begin()));
        return QueryResult(idx, lrs.get_lines());
    }

    string rep() const override {
        return "(" + l->rep() + " & " + r->rep() + ")";
    }
};

class OrQuery : public BinaryQuery {
   public:
    OrQuery(shared_ptr<BaseQuery> l, shared_ptr<BaseQuery> r) : BinaryQuery(l, r) {}

    QueryResult eval(const TextQuery& tq) const override {
        auto lrs = l->eval(tq), rrs = r->eval(tq);
        auto lidx = lrs.get_idx(), ridx = rrs.get_idx();

        shared_ptr<set<int>> idx = make_shared<set<int>>();
        std::set_union(lidx->begin(), lidx->end(), ridx->begin(), ridx->end(), inserter(*idx, idx->begin()));
        return QueryResult(idx, lrs.get_lines());
    }

    string rep() const override {
        return "(" + l->rep() + " | " + r->rep() + ")";
    }
};

class Query {
   public:
    shared_ptr<BaseQuery> bq;

    Query(const shared_ptr<BaseQuery> bq) : bq(bq) {}

    Query(const string& s) {
        bq = shared_ptr<BaseQuery>(new WordQuery(s));
    }

    QueryResult eval(const TextQuery& tq) const {
        return bq->eval(tq);
    }

    string rep() const {
        return bq->rep();
    }
};

Query operator~(const Query& q) {
    return Query(shared_ptr<BaseQuery>(new NotQuery(q.bq)));
}
Query operator&(const Query& l, const Query& r) {
    return Query(shared_ptr<BaseQuery>(new AndQuery(l.bq, r.bq)));
}
Query operator|(const Query& l, const Query& r) {
    return Query(shared_ptr<BaseQuery>(new OrQuery(l.bq, r.bq)));
}

ostream& operator<<(ostream& os, const Query query) {
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
    // test1();

    Query q = Query("aa") | Query("b") & ~Query("c");
    cout << (q) << endl;

    q = Query("aa") | (Query("b") & ~Query("c"));
    cout << (q) << endl;

    q = (Query("a") & (Query("b")) | (Query("c") & Query("d")));
    cout << (q) << endl;
}