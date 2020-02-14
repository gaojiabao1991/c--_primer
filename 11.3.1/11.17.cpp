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
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

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
using std::ifstream;
using std::initializer_list;
using std::inserter;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::map;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

int main(int argc, char **argv) {
    vector<string> v = {"a", "b", "c"};
    multiset<string> m;

    copy(v.begin(), v.end(), inserter(m, m.begin()));  //OK, set has function insert;
    // copy(v.begin(), v.end(), back_inserter(m)); //ERROR, set has not function push_back

    for (auto &s : m) {
        cout << (s) << endl;
    }

    cout << ("==========") << endl;

    v.clear();
    m = {"a", "b", "c"};
    // copy(m.begin(), m.end(), inserter(v, v.begin())); //OK, vector has function insert
    copy(m.begin(), m.end(), back_inserter(v));  //OK, vector has function push_back
    for (auto &s : v) {
        cout << (s) << endl;
    }
}