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
using std::string;
using std::vector;

int main() {
    int a = ~'q';
    for (int bit = 31; bit >=0; bit--) {
        cout << ((a & (1 << bit)) != 0);
    }

    cout << "" <<endl;
    int b = ~'q'<<6;
    for (int bit = 31; bit >=0; bit--) {
        cout << ((b & (1 << bit)) != 0);
    }
    cout << "" <<endl;
    cout << b <<endl;
}