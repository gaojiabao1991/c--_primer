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
#include "Sales_data.h"

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

namespace std {
template <>
struct hash<Sales_data> {
    typedef size_t result_type;
    typedef Sales_data argument_type;

    size_t operator()(const Sales_data& s) const {
        return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
};
}  // namespace std

int main(int argc, char** argv) {
    unordered_set<Sales_data> s;
    s.insert(Sales_data("1", 2, 3.0));
    s.insert(Sales_data("1", 2, 3.0));

    s.insert(Sales_data("2", 2, 3.0));

    s.insert(Sales_data("2", 1, 3.0));
    s.insert(Sales_data("2", 1, 3.0));

    for (auto& sd : s) {
        cout << (sd) << endl;
    }
}