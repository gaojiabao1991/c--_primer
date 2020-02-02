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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 1, b = 2;

    cout << (a) << endl;
    cout << (b) << endl;
    
    swap(&a, &b);

    cout << (a) << endl;
    cout << (b) << endl;
}