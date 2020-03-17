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
#include "Shared_ptr.h"

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
// using std::shared_ptr;
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

template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
    void check() const;
    // shared_ptr<vector<T>> data;
    Shared_ptr<vector<T>> data;

    friend bool operator==<T>(const Blob<T> &a, const Blob<T> &b);

   public:
    // using size_type = vector<T>::size_type;

    typedef typename vector<T>::size_type size_type;

    Blob() : data(Shared_ptr<vector<T>>()) {}
    Blob(initializer_list<T> il) : data(Shared_ptr<vector<T>>(il)) {}

    Blob(const Blob &ori) { data = Shared_ptr<vector<T>>(*ori.data); }

    template <typename U>
    Blob(const U begin, const U end)
        : data(Shared_ptr<vector<T>>(begin, end)) {}

    Blob &operator=(const Blob &cp) {
        data = Shared_ptr<vector<T>>(*cp.data);
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

