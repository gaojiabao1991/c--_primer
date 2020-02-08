#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

int main(int argc, char **argv) {
    ifstream fin("8.10.cpp");
    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }

    istringstream sin;
    string word;
    for (auto &line : lines) {
        sin.clear();
        sin.str(line);
        while (sin >> word) {
            cout << (word) << endl;
        }
    }
}