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
using std::function;

template <typename T> class Shared_ptr {
    T* p;
    int* count;
    function<void(T*)> del = nullptr;

   public:
    Shared_ptr(T* p) : p(p), count(new int(1)) {}
    Shared_ptr(T* p, function<void(T*)> del)
        : p(p), count(new int(1)), del(del) {}
    Shared_ptr(const Shared_ptr& ori) {
        p = ori.p;
        count = ori.count;
        ++*count;
    }

    Shared_ptr() = default;
    template <typename U>
    Shared_ptr(initializer_list<U> il) : p(new T(il)), count(new int(1)) {}
    template <typename U>
    Shared_ptr(const U& begin, const U& end)
        : p(new T(begin, end)), count(new int(1)) {}

    Shared_ptr& operator=(const Shared_ptr& cp) {
        if (&cp == this) return *this;
        --*count;
        if (*count == 0) {
            del ? del(p) : delete p;
            delete count;
        }
        p = cp.p;
        count = cp.count;
        ++*count;
    }

    ~Shared_ptr() {
        --*count;
        if (*count == 0) {
            del ? del(p) : delete p;
        }
    }

    T& operator*() const { return *p; }

    T* operator->() const { return p; }
};