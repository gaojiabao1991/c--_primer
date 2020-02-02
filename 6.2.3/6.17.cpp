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

bool containsUpper(const string &s) {
    for (auto c : s) {
        if (isupper(c)) return true;
    }
    return false;
}

void toLower(string &s) {
    for (auto &c : s) {
        c = tolower(c);
    }
}

int main() {
    cout << (containsUpper("Abc")) << endl;
    cout << (containsUpper("abc")) << endl;

    string s1 = "Abc";
    cout << (s1) << endl;
    toLower(s1);
    cout << (s1) << endl;
}