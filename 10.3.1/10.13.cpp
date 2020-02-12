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
using std::vector;

bool short_than_5(string w) {
    return w.size() < 5;
}

int main(int argc, char **argv) {
    vector<string> v = {"java", "number", "c++", "create", "value"};
    auto after = std::partition(v.begin(), v.end(), short_than_5);
    while (after < v.end()) {
        cout << (*after) << endl;
        after++;
    }
}