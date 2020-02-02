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
    vector<int> b = {0, 1, 1, 2};
    vector<int> a = {0, 1, 1, 2, 3, 5, 8};

    vector<int> &s = a.size() <= b.size() ? a : b;
    vector<int> &l = a.size() <= b.size() ? b : a;

    bool prefix = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != l[i]) {
            prefix = false;
            break;
        }
    }

    if (prefix) {
        cout << ("prefix") << endl;
    } else {
        cout << ("not prefix") << endl;
    }
}