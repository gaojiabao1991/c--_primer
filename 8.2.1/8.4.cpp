#include <cstring>
#include <fstream>
#include <iostream>
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
using std::ofstream;
using std::ostream;
using std::string;
using std::vector;

int main(int argc, char **argv) {
    ifstream in("8.4.cpp");
    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }
    for (auto &line : lines) {
        cout << (line) << endl;
    }
}