#include "6.8.h"
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
    cout << (fact(5)) << endl;
}

int fact(int i) {
    int ret = 1;
    while (i > 1) {
        ret *= i--;
    }
    return ret;
}