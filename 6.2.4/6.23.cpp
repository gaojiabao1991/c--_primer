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

void a(int *b, int *e) {
    while (b != e) {
        cout << (*b++) << endl;
    }
}

void b(int *b, int size) {
    for (int i = 0; i < size; i++) {
        cout << (*b++) << endl;
    }
}

void c(int (&a)[2]) {
    for (auto i : a) {
        cout << (i) << endl;
    }
}

int main() {
    int arr[] = {1, 2};
    // a(begin(arr), end(arr));
    // b(arr, 2);
    c(arr);
}