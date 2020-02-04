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
    // Sales_data a;
    // Sales_data b("123");
    // Sales_data c("123", 5, 1.0);
    Sales_data d(cin);

    // print(cout, a) << endl;
    // print(cout, b) << endl;
    // print(cout, c) << endl;
    print(cout, d);
}
