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
using std::function;
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

template <typename T> string debug_rep(const T& o) {
    cout << ("1") << endl;
    stringstream ss;
    ss << o;
    return ss.str();
}

template <typename T> string debug_rep(T* p) {
    cout << ("2") << endl;
    stringstream ss;
    ss << p << " " << *p;
    return ss.str();
}

string debug_rep(const string& s) {
    cout << ("3") << endl;
    stringstream ss;
    ss << s;
    return ss.str();
}

string debug_rep(const char* p) {
    cout << ("4") << endl;
    return debug_rep(string(p));
}

int main(int argc, char** argv) {
    string a("abc");
    cout << (debug_rep(a)) << endl;  // 3

    cout << (debug_rep("xyz")) << endl;  // 4,3
}