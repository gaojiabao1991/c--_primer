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

struct Sales_data {
    Sales_data() = default;
    Sales_data(const string& no) : bookNo(no) {}
    Sales_data(const string& no, unsigned sold, double price) : bookNo(no), units_sold(sold), revenue(price * sold) {}
    Sales_data(istream& is);

    string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0;

    string isbn() const { return bookNo; }
    // Sales_data& combine(const Sales_data& other);
    Sales_data& operator+=(const Sales_data& other);
    double avg_price() const;
};

// Sales_data& Sales_data::combine(const Sales_data& other) {
//     units_sold += other.units_sold;
//     revenue += other.revenue;
//     return *this;
// }

Sales_data& Sales_data::operator+=(const Sales_data& other) {
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

istream& operator>>(istream& is, Sales_data& a) {
    double price;
    is >> a.bookNo >> a.units_sold >> price;

    if (!is) {
        a = Sales_data();
    }

    a.revenue = price * a.units_sold;

    return is;
}

ostream& operator<<(ostream& os, const Sales_data& a) {
    os << a.isbn() << " " << a.units_sold << " " << a.revenue << " " << a.avg_price() << endl;
    return os;
}

Sales_data operator+(const Sales_data& a, const Sales_data& b) {
    Sales_data sum = a;
    sum += b;
    return sum;
}

Sales_data::Sales_data(istream& is) {
    is >> *this;
}