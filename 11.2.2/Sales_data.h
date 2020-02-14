#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

struct Sales_data {
    Sales_data() = default;
    Sales_data(const string& no) : bookNo(no) {}
    Sales_data(const string& no, unsigned sold, double price) : bookNo(no), units_sold(sold), revenue(price * sold) {}
    Sales_data(istream& is);

    string bookNo = "";
    unsigned units_sold = 0;
    double revenue = 0;

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data& other);
    double avg_price() const;
};

Sales_data& Sales_data::combine(const Sales_data& other) {
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

istream& read(istream& is, Sales_data& a);
ostream& print(ostream& os, const Sales_data& a);
Sales_data add(const Sales_data& a, const Sales_data& b);

istream& read(istream& is, Sales_data& a) {
    double price;
    is >> a.bookNo >> a.units_sold >> price;
    a.revenue = price * a.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& a) {
    os << a.isbn() << " " << a.units_sold << " " << a.revenue << " " << a.avg_price() << endl;
    return os;
}

Sales_data add(const Sales_data& a, const Sales_data& b) {
    Sales_data sum = a;
    sum.combine(b);
    return sum;
}

Sales_data::Sales_data(istream& is) {
    read(is, *this);
}