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

int main(int argc, char **argv) {
    string s = "";
    for (int i = 1; i < argc; i++) {
        s += argv[i];
    }
    cout << (s) << endl;
}
