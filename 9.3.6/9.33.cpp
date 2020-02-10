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

void print(vector<int> &v) {
    for (auto &i : v) {
        cout << (i) << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto b = v.begin();
    while (b != v.end()) {
        b++;
        v.insert(b, 42);
        b++;
    }

    print(v);
}