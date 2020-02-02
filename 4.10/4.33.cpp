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
    int x = 0, y = 0;

    bool c = false;
    cout << (c ? (++x, ++y) : --x, --y) << endl;

    cout << ("x-> ")<<x <<endl;
    cout << ("y-> ")<<y <<endl;
}
