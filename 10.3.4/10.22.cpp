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
using namespace std::placeholders;

bool small(string& s, int sz) {
    return s.size() <= sz;
}

int main(int argc, char** argv) {
    vector<string> v = {"aaa", "aaaqaaaa", "a", "aaaaaaaa", "aaaaaaaaa"};
    int sz = 6;
    auto c = std::count_if(v.begin(), v.end(), std::bind(small, _1, sz));
    cout << (c) << endl;
}