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

using std::advance;
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

void print(list<int> &l) {
    for (auto &i : l) {
        cout << (i) << " ";
    }
    cout << endl;
}

void print(forward_list<int> &l) {
    for (auto &i : l) {
        cout << (i) << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    //删除偶数元素, 复制奇数元素
    // vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // auto b = v.begin();
    // while (b != v.end()) {
    //     if (*b % 2) {
    //         b = v.insert(b, *b);
    //         b += 2;
    //     } else {
    //         b = v.erase(b);
    //     }
    // }n
    // print(v);

    list<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto b = v.begin();
    while (b != v.end()) {
        if (*b % 2) {
            b = v.insert(b, *b);
            advance(b, 2);
        } else {
            b = v.erase(b);
        }
    }
    print(v);

    // forward_list<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // auto bb = v.before_begin();
    // auto b = v.begin();
    // while (b != v.end()) {
    //     if (*b % 2) {
    //         b = v.insert_after(b, *b);
    //         bb = b;
    //         b++;
    //     } else {
    //         b = v.erase_after(bb);
    //     }
    // }
    // print(v);
}
