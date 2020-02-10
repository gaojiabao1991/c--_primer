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
using std::distance;
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

void find_insert(forward_list<string> &l, const string &find, const string &to_insert) {
    forward_list<string>::iterator bb = l.before_begin();  //循环结束后bb指向列表的最后一个元素
    auto size = distance(l.begin(), l.end());

    for (auto b = l.begin(); b != l.end(); b++) {
        if (*b == find) b = l.insert_after(b, to_insert);
        bb = b;
    }

    if (distance(l.begin(), l.end()) == size) l.insert_after(bb, to_insert);
}

void print(forward_list<string> l) {
    for (auto &s : l) {
        cout << (s) << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    forward_list<string> l = {"abc", "def", "abc", "ghi"};
    find_insert(l, "abc", "insertion");
    // find_insert(l, "xyz", "insertion");
    print(l);
}