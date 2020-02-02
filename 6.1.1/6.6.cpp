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

size_t count_calls() {
    static size_t cc = 0;
    return ++cc;
}

int main() {
    for (int i = 0; i < 5; i++) {
        cout << (count_calls()) << endl;
    }
}