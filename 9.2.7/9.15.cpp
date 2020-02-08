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

bool eq(vector<int> a, vector<int> b) {
    return a == b;
}

bool eq(vector<int> a, list<int> b) {
    if (a.size() != b.size()) return false;

    int idx = 0;
    for (auto &bi : b) {
        if (a[idx] != bi) return false;
        idx++;
    }
    return true;
}

int main(int argc, char **argv) {
}