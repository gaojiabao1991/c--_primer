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

istream& print(istream& is) {
    string s;
    while (is >> s) {
        cout << (s) << endl;
    }
    is.clear();
}

int main(int argc, char** argv) {
    print(cin);
}