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
    int x[10];
    int *p = x;

    // cout << (x) << endl;
    // cout << (p) << endl;
    // cout << (*p) << endl;

    cout << (sizeof(x) / sizeof(*x)) << endl;

    cout << (sizeof(p) / sizeof(*p)) << endl;
}