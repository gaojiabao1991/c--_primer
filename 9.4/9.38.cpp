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
    // vector<int> a(10, 1);
    // cout << (a.size()) << endl;
    // cout << (a.capacity()) << endl;

    // a.push_back(1);
    // cout << (a.size()) << endl;
    // cout << (a.capacity()) << endl;

    vector<int> a;
    for (int i = 0; i < 100; i++) {
        a.push_back(i);
        cout << "size: " << (a.size()) << " cap: " << a.capacity() << endl;
    }
}