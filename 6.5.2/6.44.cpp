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

inline const string &isShorter(const string &a, const string &b) {
    if (a.size() < b.size()) return a;
    return b;
}

int main(int argc, char **argv) {
    cout << (isShorter("ab", "abc")) << endl;
    cout << (isShorter("def", "de")) << endl;
}