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

template <typename I, typename V>
I my_find(const I& begin, const I& end, const V& v) {
    I p = begin;
    while (p != end) {
        if (*p == v) return p;
        ++p;
    }
    return end;
}

int main(int argc, char** argv) {
    vector<int> vec = {1, 3, 5, 7, 9};
    auto p = my_find(vec.begin(), vec.end(), 5);
    cout << (*p == 5) << endl;

    auto p2 = my_find(vec.begin(), vec.end(), 15);
    cout << (p2 == vec.end()) << endl;

    cout << ("=====") << endl;
    list<string> l = {"1", "3", "5", "7", "9"};
    auto p3 = my_find(l.begin(), l.end(), "5");
    cout << (*p3 == "5") << endl;
    auto p4 = my_find(l.begin(), l.end(), "15");
    cout << (p4 == l.end()) << endl;
}