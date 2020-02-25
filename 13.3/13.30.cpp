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
using std::swap;
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using namespace std::placeholders;

class HasPtr {
   public:
    friend void swap(HasPtr& a, HasPtr& b);
    HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr& ori) : ps(new string(*ori.ps)), i(ori.i) {}
    HasPtr& operator=(const HasPtr& cp) {
        string* new_ps = new string(*cp.ps);
        delete ps;
        ps = new_ps;
        i = cp.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }

    string& get() {
        return *ps;
    }

   private:
    string* ps;
    int i;
};

inline void swap(HasPtr& a, HasPtr& b) {
    cout << ("swap") << endl;
    std::swap(a.ps, b.ps);
    std::swap(a.i, b.i);
}

int main(int argc, char const* argv[]) {
    HasPtr a("abc");
    HasPtr b("xyz");

    swap(a, b);

    cout << (a.get()) << endl;
    cout << (b.get()) << endl;


}
