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
using std::string;
using std::vector;

int main(int argc, char **argv) {
    if (cin) {
        Sales_data total(cin);

        while (true) {
            Sales_data next(cin);
            if (not cin) break;

            if (next.isbn() == total.isbn()) {
                total.combine(next);
            } else {
                print(cout, total) << endl;
                total = next;
            }
        }

        print(cout, total) << endl;
    } else {
        cerr << ("no data!") << endl;
    }
}