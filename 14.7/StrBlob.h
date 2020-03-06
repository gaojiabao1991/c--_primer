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
using std::runtime_error;
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
using namespace std::placeholders;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    void check() const;
    shared_ptr<vector<string>> data;
    friend bool operator==(const StrBlob& a, const StrBlob& b);

   public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    using size_type = vector<string>::size_type;

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    StrBlob(const StrBlob& ori) {
        data = make_shared<vector<string>>(*ori.data);
    }

    StrBlob& operator=(const StrBlob& cp) {
        data = make_shared<vector<string>>(*cp.data);
        return *this;
    }

    string& operator[](size_type n) {
        return (*data)[n];
    }

    const string& operator[](size_type n) const {
        return (*data)[n];
    }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& s) { data->push_back(s); }
    void push_back(string&& s) { data->push_back(std::move(s)); }
    void pop_back() { data->pop_back(); }

    string& back();
    const string& back() const;
    string& front();
    const string& front() const;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
};

bool operator==(const StrBlob& a, const StrBlob& b) {
    return *(a.data) == *(b.data);
}

bool operator!=(const StrBlob& a, const StrBlob& b) {
    return !(a == b);
}

class StrBlobPtr {
   public:
    using size_type = vector<string>::size_type;
    friend bool operator==(const StrBlobPtr& a, const StrBlobPtr& b);
    friend StrBlobPtr operator+(const StrBlobPtr& ptr, const int& offset);
    friend StrBlobPtr operator-(const StrBlobPtr& ptr, const int& offset);

    StrBlobPtr(StrBlob& blob, size_type idx = 0) : data(blob.data), cur(idx) {}
    StrBlobPtr(const StrBlob& blob, size_type idx = 0) : data(blob.data), cur(idx) {}
    string& deref() const;
    StrBlobPtr& inc();
    StrBlobPtr& advance(size_type inc);
    string& operator[](size_type n);
    const string& operator[](size_type n) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

   private:
    shared_ptr<vector<string>> check(size_type idx) const;
    weak_ptr<vector<string>> data;
    size_type cur = 0;
};

class ConstStrBlobPtr {
   public:
    using size_type = vector<string>::size_type;
    ConstStrBlobPtr(StrBlob& blob, size_type idx = 0) : data(blob.data), cur(idx) {}
    ConstStrBlobPtr(const StrBlob& blob, size_type idx = 0) : data(blob.data), cur(idx) {}

    const string& operator*() const{
        auto p = check(cur);
        return (*p)[cur];
    }

    const string* operator->() const{
        return &this->operator*();
    }

   private:
    shared_ptr<vector<string>> check(size_type idx) const;
    weak_ptr<vector<string>> data;
    size_type cur = 0;
};

bool operator==(const StrBlobPtr& a, const StrBlobPtr& b) {
    shared_ptr<vector<string>> s_ptr_a = a.data.lock();
    auto s_ptr_b = b.data.lock();
    if (s_ptr_a && s_ptr_b) {
        if (s_ptr_a == s_ptr_b && a.cur == b.cur) {
            return true;
        }
    }
    return false;
}

bool operator!=(const StrBlobPtr& a, const StrBlobPtr& b) {
    return !(a == b);
}

StrBlobPtr& StrBlobPtr::operator++() {
    check(cur);
    ++cur;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    --cur;
    check(cur);
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr pre = *this;
    ++*this;
    return pre;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr pre = *this;
    --*this;
    return pre;
}

StrBlobPtr operator+(const StrBlobPtr& ptr, const int& offset) {
    StrBlobPtr ret = ptr;
    ret.cur += offset;
    ret.check(ret.cur - 1);
    return ret;
}

StrBlobPtr operator-(const StrBlobPtr& ptr, const int& offset) {
    StrBlobPtr ret = ptr;
    ret.cur -= offset;
    ret.check(ret.cur);
    return ret;
}

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

StrBlobPtr& StrBlobPtr::advance(size_type inc) {
    check(cur);
    cur += inc;
    return *this;
}

string& StrBlobPtr::operator[](size_type n) {
    auto s_ptr = data.lock();
    if (!s_ptr) throw new runtime_error("data weak_ptr expired");
    return (*s_ptr)[n];
}

const string& StrBlobPtr::operator[](size_type n) const {
    auto s_ptr = data.lock();
    if (!s_ptr) throw new runtime_error("data weak_ptr expired");
    return (*s_ptr)[n];
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

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this, 0);
}

ConstStrBlobPtr StrBlob::end() const {
    return ConstStrBlobPtr(*this, data->size());
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_type idx) const {
    shared_ptr<vector<string>> sp = data.lock();
    if (!sp) {
        throw std::runtime_error("weak ptr expired");
    }
    if (idx >= sp->size()) {
        throw runtime_error("out of index");
    }
    return sp;
}
