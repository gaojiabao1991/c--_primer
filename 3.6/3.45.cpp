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
    int ia[3][4];
    int i = 0;
    for (auto &row : ia) {
        for (auto &e : row) {
            e = i;
            i++;
        }
    }

    //   for (auto &row : ia) {
    //     for (int e : row) cout << e << endl;
    //   }

    //   for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) cout << ia[i][j] << endl;
    //   }

    for (auto *p = ia; p < end(ia); p++) {
        for (auto q = *p; q < end(*p); q++) cout << *q << endl;
    }

    for (auto p = ia; p < end(ia); p++) {
        for (auto q = *p; q < end(*p); q++) cout << *q << endl;
    }
}