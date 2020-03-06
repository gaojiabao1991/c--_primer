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

int main(int argc, char **argv) {
    vector<int> vec = {1, 2, 3, 1024, 1025, 1026};
    int c = std::count_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), _1, 1024));
    cout << "a: " << (c) << endl;

    vector<string> vec2 = {"pooh", "pooh", "pooh", "pooh", "abc", "pooh"};
    auto p = std::find_if(vec2.begin(), vec2.end(), std::bind(std::not_equal_to<string>(), _1, "pooh"));
    cout << ("b: ") << *p << endl;

    vector<int> vec3 = {1, 2, 3, 4, 5};
    std::transform(vec3.begin(), vec3.end(), vec3.begin(), std::bind(std::multiplies<int>(), _1, 2));
    cout << ("c: ");
    for (auto &i : vec3) {
        cout << (i) << " ";
    }
    cout << endl;
}