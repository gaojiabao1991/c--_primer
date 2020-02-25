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

class HasPtr {
   public:
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new unsigned(1)) {}
    HasPtr(const HasPtr& ori) : ps(ori.ps), i(ori.i), use(ori.use) {
        ++*ori.use;
    }
    HasPtr& operator=(const HasPtr& cp) {
        if (--*use == 0) {
            delete ps;
            delete use;
        }

        ps = cp.ps;
        i = cp.i;
        use = cp.use;
        ++*cp.use;

        return *this;
    }

    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

    string get() {
        return *ps;
    }

    void set(string s) {
        *ps = s;
    }

   private:
    string* ps;
    int i;
    unsigned* use;
};

int main(int argc, char** argv) {
    HasPtr p1 = HasPtr("abc");
    HasPtr p2 = p1;

    cout << (p1.get()) << endl;
    cout << (p2.get()) << endl;

    p2.set("xyz");

    cout << (p1.get()) << endl;
    cout << (p2.get()) << endl;
}
