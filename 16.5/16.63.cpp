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

template <typename T>
size_t count(const T& val, const vector<T>& vec) {
    size_t c = 0;
    for (auto& e : vec) {
        if (e == val) ++c;
    }
    return c;
}

template <>
size_t count(const char* const& val, const vector<const char*>& vec) {
    size_t c = 0;
    for (auto& e : vec) {
        if (string(val) == string(e)) ++c;
    }
    return c;
}

int main(int argc, char** argv) {
    vector<int> v1 = {1, 2, 3, 4, 4, 5};
    cout << (count(4, v1)) << endl;

    vector<double> v2 = {1.0, 2.0, 2.0, 2.0, 3.0};
    cout << (count(2.0, v2)) << endl;

    vector<string> v3 = {"a", "a", "a", "b", "c"};
    cout << (count(string("b"), v3)) << endl;

    vector<const char*> v4 = {"a", "a", "a", "b", "c"};
    const char* p = "a";
    cout << (count(p, v4)) << endl;
}