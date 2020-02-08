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
    Sales_data i("No.123", 10, 20.0);
    string s = "abc";

    i.combine(s);

    print(cout, i);
}