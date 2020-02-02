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

void reset(int &i) {
    i = 0;
}

int main() {
    int a = 42;
    cout << (a) << endl;
    reset(a);
    cout << (a) << endl;
}