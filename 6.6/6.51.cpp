#include "6.51.h"
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
using std::string;
using std::vector;

void f() {
    cout << (1) << endl;
}
void f(int a) {
    cout << (2) << endl;
}
void f(int a, int b) {
    cout << (3) << endl;
}

void f(double a, double b = 3.14) {
    cout << (4) << endl;
    cout << a << " " << (b) << endl;
}

int main(int argc, char **argv) {
    // f(2.56, 42);
    f(2.56, 3.14);
}