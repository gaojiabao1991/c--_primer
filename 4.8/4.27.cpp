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
    unsigned long ul1 = 3, ul2 = 7;

    cout << (ul1 & ul2) << endl;
    cout << (ul1 | ul2) << endl;
    cout << (ul1 && ul2) << endl;
    cout << (ul1 || ul2) << endl;
}