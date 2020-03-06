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

   public:
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
        //TODO
    }

    string rep() const override {
        return "~(" + bq->rep() + ")";
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
        //TODO
    }

    string rep() const override {
        return "(" + l->rep() + ")" + " & " + "(" + r->rep() + ")";
    }
};

class OrQuery : public BinaryQuery {
   public:
    OrQuery(shared_ptr<BaseQuery> l, shared_ptr<BaseQuery> r) : BinaryQuery(l, r) {}

    QueryResult eval(const TextQuery& tq) const override {
        //TODO
    }

    string rep() const override {
        return "(" + l->rep() + ")" + " | " + "(" + r->rep() + ")";
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

int main(int argc, char** argv) {
    // ifstream ifs("story.txt");
    // TextQuery tq(ifs);
    // QueryResult rs = tq.query("bird");
    // rs.print();

    Query q("abc");
    cout << (q) << endl;

    Query nq = ~q;
    cout << (nq) << endl;

    Query andq = q & nq;
    cout << (andq) << endl;

    Query orq = q | nq;
    cout << (orq) << endl;

    Query comq = andq & orq;
    cout << (comq) << endl;
}