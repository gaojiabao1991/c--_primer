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

void swp(int *&a, int *&b) {
    int *tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x = 1, y = 2;
    int *a = &x, *b = &y;

    cout << (*a) << endl;
    cout << (*b) << endl;

    swp(a, b);

    cout << (*a) << endl;
    cout << (*b) << endl;
}