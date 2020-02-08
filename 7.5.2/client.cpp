#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

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

int main(int argc, char **argv) {
    Sales_data a;
    print(cout, a);

    Sales_data b("No.123");
    print(cout, b);

    Sales_data c("No.345", 10, 20.0);
    print(cout, c);

    Sales_data d(cin);
    print(cout, d);
}