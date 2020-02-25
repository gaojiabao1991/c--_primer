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

class StrVec {
    static allocator<string> alloc;

    string* elements;
    string* first_free;
    string* cap;

    void free() {
        if (elements) {
            // for (auto p = first_free - 1; p >= elements; p--) {
            //     alloc.destroy(p);
            // }
            std::for_each(elements, first_free, [](string& p) { alloc.destroy(&p); });
            alloc.deallocate(elements, capacity());
        }
    }

    // 重新调整大小, 保证至少有一个空闲位置
    void check_n_alloc() {
        if (first_free != cap) return;

        size_t new_cap = size() ? size() * 2 : 1;
        reserve(new_cap);
    }

    pair<string*, string*> copy_from(StrVec& cp) {
        if (cp.elements) {
            size_t sz = cp.first_free - cp.elements;
            string* new_elements = alloc.allocate(sz);
            std::uninitialized_copy_n(cp.elements, sz, new_elements);
            return {new_elements, new_elements + sz};
        } else {
            return {nullptr, nullptr};
        }
    }

   public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){};
    StrVec(initializer_list<string> il) {
        elements = alloc.allocate(il.size());

        auto p = elements;
        for (auto& s : il) {
            alloc.construct(p++, s);
        }

        first_free = cap = p;
    }
    StrVec(StrVec& ori) {
        auto data = copy_from(ori);
        elements = data.first;
        first_free = cap = data.second;
    }
    StrVec& operator=(StrVec& cp) {
        auto data = copy_from(cp);
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    ~StrVec() {
        free();
    }

    void push_back(const string& s) {
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
        string* new_elements = alloc.allocate(n);
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
        string* new_elements = alloc.allocate(new_size);
        size_t sz = size();
        size_t min = std::min(new_size, sz);
        for (int i = 0; i < min; i++) {
            alloc.construct(new_elements + i, std::move(*(elements + i)));
        }
        // 多余的位置用默认值填充
        if (new_size > sz) std::uninitialized_fill_n(new_elements + sz, new_size - sz, string());
        free();
        elements = new_elements;
        first_free = cap = new_elements + new_size;
    }

    string* begin() {
        return elements;
    }

    string* end() {
        return first_free;
    }

    const string& get(size_t i) {
        return *(elements + i);
    }
};

allocator<string> StrVec::alloc = allocator<string>();
