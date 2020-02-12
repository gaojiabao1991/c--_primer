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
#include "Sales_item.h"

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
using std::forward_list;
using std::front_inserter;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

int main(int argc, char** argv) {
    istream_iterator<Sales_item> in_it(cin), eof;

    vector<Sales_item> v;
    copy(in_it, eof, back_inserter(v));
    auto cmp = [](const Sales_item& a, const Sales_item& b) { return a.isbn() < b.isbn(); };
    sort(v.begin(), v.end(), cmp);

    auto begin = v.begin();
    while (begin != v.end()) {
        auto end = std::find_if(begin,
                                v.end(),
                                [&](Sales_item item) { return item.isbn() != (*begin).isbn(); });
        auto sum = std::accumulate(begin + 1, end, *begin);
        cout << (sum) << endl;
        begin = end;
    }
}