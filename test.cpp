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
using std::string;
using std::vector;
using namespace std::placeholders;

int main(int argc, char **argv) {
    vector<int> v = {1, 2, 5, 3, 6};
    int threshold = 6;
    // bool check(int i, int threshold) {
    //     return i >= threshold;
    // }
    auto check = [](int i, int limit) { return i >= limit; };
    auto check_lambda = [threshold, check](int i) { return check(i, threshold); };
    auto check_bind = std::bind(check, _1, threshold);

    auto p_larger = std::find_if(v.begin(), v.end(), check_bind);
    cout << (*p_larger) << endl;
}