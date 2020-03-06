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

class String {
    static allocator<char> alloc;
    char* b;
    char* e;

   public:
    String() : b(nullptr), e(nullptr) {}
    String(const char* cstyle) {
        cout << ("construct by cstyle: ") << cstyle << endl;
        auto sz = strlen(cstyle);
        b = alloc.allocate(sz);
        for (auto i = 0; i < sz; i++) {
            *(b + i) = *(cstyle + i);
            alloc.construct(b + i, *(cstyle + i));
        }
        e = b + sz;
    }

    String(const String& ori) {
        cout << ("construct by String: ") << ori.get() << endl;
        auto sz=ori.size();
        b = alloc.allocate(sz);
        for (int i = 0; i < sz; i++) {
            alloc.construct(b + i, *(ori.b + i));
        }
        e = b + sz;
    }

    String& operator=(const String& cp) {
        cout << ("operator= : ") << cp.get() << endl;
        auto new_b = alloc.allocate(cp.size());

        for (int i = 0; i < cp.size(); i++) {
            alloc.construct(new_b + i, *(cp.b + i));
        }
        free();
        b = new_b;
        e = new_b + cp.size();
    }

    void free() {
        if (!b) return;
        for (auto p = b; p != e; p++) {
            alloc.destroy(p);
        }
        alloc.deallocate(b, e - b);
    }

    ~String() {
        free();
    }

    size_t size() const {
        return e - b;
    }

    void print() {
        for (auto p = b; p != e; p++) {
            cout << (*p) << endl;
        }
    }

    string get() const {
        string s;
        for (auto p = b; p != e; p++) {
            s += *p;
        }
        return s;
    }
};

allocator<char> String::alloc = allocator<char>();