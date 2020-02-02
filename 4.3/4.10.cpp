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
    int i;
    cin >> i;
    while (i != 42) {
        cout << i << endl;
        cin >> i;
    }
}