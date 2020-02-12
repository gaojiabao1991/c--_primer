#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::begin;
using std::cerr;
using std::cin;
using std::copy;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;

int main(int argc, char** argv) {
    vector<string> v = {"aaa", "b", "c", "c", "bb", "cc", "xx", "xyz", "dd", "a", "bb", "aaa", "bbb"};
    auto c = std::count_if(v.begin(), v.end(), [](const string& s) { return s.size() >= 3; });
    cout << (c) << endl;
}