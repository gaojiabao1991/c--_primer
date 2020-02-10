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

void print(forward_list<int> l) {
    for (auto &i : l) {
        cout << (i) << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    forward_list<int> l(begin(ia), end(ia));
    print(l);

    forward_list<int>::iterator bb = l.before_begin();
    forward_list<int>::iterator b = l.begin();

    while (b != l.end()) {
        if (*b % 2) {
            b = l.erase_after(bb);
        } else {
            b++;
            bb++;
        }
    }

    print(l);
}