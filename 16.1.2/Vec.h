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

template <typename T> class Vec {
    static allocator<T> alloc;
    T* elements;
    T* first_free;
    T* cap;

    void free() {
        if (elements) {
            // for (auto p = first_free - 1; p >= elements; p--) {
            //     alloc.destroy(p);
            // }
            std::for_each(elements, first_free,
                          [](T& p) { alloc.destroy(&p); });
            alloc.deallocate(elements, capacity());
        }
    }

    // 重新调整大小, 保证至少有一个空闲位置
    void check_n_alloc() {
        if (first_free != cap) return;

        size_t new_cap = size() ? size() * 2 : 1;
        reserve(new_cap);
    }

    pair<T*, T*> copy_from(Vec& cp) {
        if (cp.elements) {
            size_t sz = cp.first_free - cp.elements;
            T* new_elements = alloc.allocate(sz);
            std::uninitialized_copy_n(cp.elements, sz, new_elements);
            return {new_elements, new_elements + sz};
        } else {
            return {nullptr, nullptr};
        }
    }

   public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(initializer_list<T> il) {
        elements = alloc.allocate(il.size());

        auto p = elements;
        for (auto& s : il) {
            alloc.construct(p++, s);
        }

        first_free = cap = p;
    }

    Vec(Vec& ori) {
        auto data = copy_from(ori);
        elements = data.first;
        first_free = cap = data.second;
    }

    Vec(Vec&& ori) noexcept
        : elements(ori.elements), first_free(ori.first_free), cap(ori.cap) {
        ori.elements = ori.first_free = ori.cap = nullptr;
    }

    Vec& operator=(Vec& cp) {
        auto data = copy_from(cp);
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    Vec& operator=(Vec&& cp) {
        if (&cp != this) {
            free();
            elements = cp.elements;
            first_free = cp.first_free;
            cap = cp.cap;
            cp.elements = cp.first_free = cp.cap = nullptr;
        }
        return *this;
    }

    ~Vec() { free(); }

    void push_back(const T& s){
        check_n_alloc();
        alloc.construct(first_free++, s);
    }

    size_t size() {
        return first_free - elements;
    }

    size_t capacity() {
        return cap - elements;
    }

    void reserve(size_t n) {
        if (n <= capacity()) return;
        T* new_elements = alloc.allocate(n);
        size_t sz = size();
        for (int i = 0; i < sz; i++) {
            alloc.construct(new_elements + i, std::move(*(elements + i)));
        }
        free();
        elements = new_elements;
        first_free = new_elements + sz;
        cap = new_elements + n;
    }

    void resize(size_t new_size) {
        T* new_elements = alloc.allocate(new_size);
        size_t sz = size();
        size_t min = std::min(new_size, sz);
        for (int i = 0; i < min; i++) {
            alloc.construct(new_elements + i, std::move(*(elements + i)));
        }
        // 多余的位置用默认值填充
        if (new_size > sz) std::uninitialized_fill_n(new_elements + sz, new_size - sz, T());
        free();
        elements = new_elements;
        first_free = cap = new_elements + new_size;
    }

    T* begin() {
        return elements;
    }

    T* end() {
        return first_free;
    }

    const T& get(size_t i) {
        return *(elements + i);
    }
};

template <typename T> allocator<T> Vec<T>::alloc = allocator<T>();