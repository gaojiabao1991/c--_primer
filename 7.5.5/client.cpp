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
    Sales_data item = {"No.123", 25, 15.99};
    cout << (item.isbn) << endl;
    cout << (item.sold) << endl;
    cout << (item.revenue) << endl;
}