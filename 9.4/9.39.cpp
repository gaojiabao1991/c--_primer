#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

int main(int argc, char **argv) {
    vector<string> v;
    v.reserve(1024);
    string word;
    while (cin >> word) {
        v.push_back(word);
    }
    v.resize(v.size() + v.size() / 2);

    cout << (v.capacity()) << endl;
    cout << (v.size()) << endl;
    for (auto &s : v) {
        cout << (s) << endl;
    }
}