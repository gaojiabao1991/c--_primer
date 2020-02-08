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
using std::swap;
using std::vector;

int main(int argc, char **argv) {
    // array<int, 10> a = {1, 2, 3, 4, 5};
    // a = {2, 3, 4, 5, 6};

    // for (auto &i : a) {
    //     cout << (i) << endl;
    // }

    // int a = 1;
    // int b = 2;
    // swap(a, b);

    // cout << (a) << endl;
    // cout << (b) << endl;

    list<int> l = {1, 2, 3, 4, 5};
    l.assign({2, 3, 4});
    for (auto &i : l) {
        cout << (i) << endl;
    }
}