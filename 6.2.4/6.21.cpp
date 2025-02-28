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

int getLarger(int a, const int *b) {
    if (a > *b) return a;
    return *b;
}

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    cout << (getLarger(a, &b)) << endl;
    cout << (getLarger(d, &c)) << endl;
}