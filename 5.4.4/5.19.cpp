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
    do {
        cout << ("input two string") << endl;
        string a, b;
        cin >> a >> b;
        if (b.size() < a.size()) a = b;
        cout << ("the shorter one is : ") << a << endl;
    } while (true);
}