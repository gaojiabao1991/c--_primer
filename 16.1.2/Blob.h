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

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    void check() const;
    shared_ptr<vector<T>> data;
    friend bool operator==<T>(const Blob<T> &a, const Blob<T> &b);

   public:
    // using size_type = vector<T>::size_type;

    typedef typename vector<T>::size_type size_type;

    Blob() : data(make_shared<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

    Blob(const Blob &ori) { data = make_shared<vector<T>>(*ori.data); }

    Blob &operator=(const Blob &cp) {
        data = make_shared<vector<T>>(*cp.data);
        return *this;
    }

    T &operator[](size_type n) { return (*data)[n]; }

    const T &operator[](size_type n) const { return (*data)[n]; }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T &s) { data->push_back(s); }
    void push_back(T &&s) { data->push_back(std::move(s)); }
    void pop_back() { data->pop_back(); }

    T &back();
    const T &back() const;
    T &front();
    const T &front() const;

    BlobPtr<T> begin();
    BlobPtr<T> end();
};

template <typename T> void Blob<T>::check() const {
    if (data->empty()) {
        throw std::out_of_range("data is empty");
    }
}

template <typename T> const T &Blob<T>::front() const {
    check();
    return data->front();
}

template <typename T> T &Blob<T>::front() {
    check();
    return data->front();
}

template <typename T> const T &Blob<T>::back() const {
    check();
    return data->back();
}

template <typename T> T &Blob<T>::back() {
    check();
    return data->back();
}

template <typename T> bool operator==(const Blob<T> &a, const Blob<T> &b) {
    return *(a.data) == *(b.data);
}

template <typename T> bool operator!=(const Blob<T> &a, const Blob<T> &b) {
    return !(a == b);
}

template <typename T> bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &ptr, const int &offset);
template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &ptr, const int &offset);\

template <typename T> class BlobPtr {
   public:
    // using size_type = vector<T>::size_type;
    typedef typename vector<T>::size_type size_type;

    friend bool operator==<T>(const BlobPtr<T> &a, const BlobPtr<T> &b);
    friend BlobPtr operator+<T>(const BlobPtr<T> &ptr, const int &offset);
    friend BlobPtr operator-<T>(const BlobPtr<T> &ptr, const int &offset);

    BlobPtr(const Blob<T> &blob, size_type idx = 0)
        : data(blob.data), cur(idx) {}

    BlobPtr &advance(size_type inc);

    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

    const T &operator*() const {
        auto p = check(cur);
        return (*p)[cur];
    }

    const T *operator->() const { return &this->operator*(); }

   private:
    shared_ptr<vector<T>> check(size_type idx) const;
    weak_ptr<vector<T>> data;
    size_type cur = 0;
};

template <typename T> BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this, 0);
}

template <typename T> BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, data->size());
}

template <typename T>
bool operator==(const BlobPtr<T> &a, const BlobPtr<T> &b) {
    shared_ptr<vector<T>> s_ptr_a = a.data.lock();
    auto s_ptr_b = b.data.lock();
    if (s_ptr_a && s_ptr_b) {
        if (s_ptr_a == s_ptr_b && a.cur == b.cur) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool operator!=(const BlobPtr<T> &a, const BlobPtr<T> &b) {
    return !(a == b);
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator++() {
    check(cur);
    ++cur;
    return *this;
}

template <typename T> BlobPtr<T> &BlobPtr<T>::operator--() {
    --cur;
    check(cur);
    return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr pre = *this;
    ++*this;
    return pre;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr pre = *this;
    --*this;
    return pre;
}

template <typename T>
BlobPtr<T> operator+(const BlobPtr<T> &ptr, const int &offset) {
    BlobPtr<T> ret = ptr;
    ret.cur += offset;
    ret.check(ret.cur - 1);
    return ret;
}

template <typename T>
BlobPtr<T> operator-(const BlobPtr<T> &ptr, const int &offset) {
    BlobPtr<T> ret = ptr;
    ret.cur -= offset;
    ret.check(ret.cur);
    return ret;
}

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_type idx) const {
    shared_ptr<vector<T>> sp = data.lock();
    if (!sp) {
        throw std::runtime_error("weak ptr expired");
    }
    if (idx >= sp->size()) {
        throw runtime_error("out of index");
    }
    return sp;
}

template <typename T> BlobPtr<T> &BlobPtr<T>::advance(size_type inc) {
    check(cur);
    cur += inc;
    return *this;
}