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

int fact(int i) {
    int ret = 1;
    while (i > 1) {
        ret *= i--;
    }
    return ret;
}

int myAbs(int i) {
    if (i < 0) i = i * (-1);
    return i;
}

int main() {
    while (true) {
        cout << ("input number") << endl;
        int i;
        cin >> i;
        // cout << (fact(i)) << endl;
        cout << (myAbs(i)) << endl;
    }
}
