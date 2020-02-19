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
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using std::runtime_error;
using namespace std::placeholders;

class StrBlobPtr;

class StrBlob {
   public:
    friend class StrBlobPtr;

    using size_type = vector<string>::size_type;

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& s) { data->push_back(s); }
    void pop_back() { data->pop_back(); }

    string& back();
    const string& back() const;
    string& front();
    const string& front() const;

    StrBlobPtr begin();
    StrBlobPtr end();

    const StrBlobPtr begin() const;
    const StrBlobPtr end() const;

   private:
    void check() const;
    shared_ptr<vector<string>> data;
};

class StrBlobPtr {
   public:
    using size_type = vector<string>::size_type;

    StrBlobPtr(StrBlob& blob, size_type idx) : data(blob.data), cur(idx) {}
    StrBlobPtr(const StrBlob& blob, size_type idx) : data(blob.data), cur(idx) {}
    string& deref() const;
    StrBlobPtr& inc();

   private:
    shared_ptr<vector<string>> check(size_type idx) const;
    weak_ptr<vector<string>> data;
    size_type cur = 0;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_type idx) const {
    shared_ptr<vector<string>> sp = data.lock();
    if (!sp) {
        throw std::runtime_error("weak ptr expired");
    }
    if (idx >= sp->size()) {
        throw runtime_error("out of index");
    }
    return sp;
}

string& StrBlobPtr::deref() const {
    auto sp = check(cur);
    return (*sp)[cur];
}

StrBlobPtr& StrBlobPtr::inc() {
    check(cur);
    cur++;
    return *this;
}

void StrBlob::check() const {
    if (data->empty()) {
        throw std::out_of_range("data is empty");
    }
}

const string& StrBlob::front() const {
    check();
    return data->front();
}

string& StrBlob::front() {
    check();
    return data->front();
}

const string& StrBlob::back() const {
    check();
    return data->back();
}

string& StrBlob::back() {
    check();
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

const StrBlobPtr StrBlob::begin() const{
    return StrBlobPtr(*this, 0);
}

const StrBlobPtr StrBlob::end() const{
    return StrBlobPtr(*this, data->size());
}