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

int &get(int *arr, int idx) {
    return *(arr + idx);
}

int main(int argc, char **argv) {
    int ia[10];
    for (int i = 0; i < 10; i++) {
        get(ia, i) = i;
    }

    for (auto &i : ia) cout << (i) << endl;
}