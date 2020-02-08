#include <cstring>
#include <fstream>
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
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::ofstream;
using std::ostream;
using std::string;
using std::vector;

int main(int argc, char **argv) {
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ofstream::app);

    Sales_data total;
    if (read(fin, total)) {
        Sales_data next;
        while (read(fin, next)) {
            if (next.isbn() == total.isbn()) {
                total.combine(next);
            } else {
                print(fout, total) << endl;
                total = next;
            }
        }
        print(fout, total) << endl;
    } else {
        cerr << ("no data!") << endl;
    }
}