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
    string s = "word";
    string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    cout << p1 <<endl;
}