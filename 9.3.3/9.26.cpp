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

void print(int* b, int* e) {
    while (b != e) {
        cout << (*b) << " ";
        b++;
    }
    cout << endl;
}

void print(vector<int> v) {
    auto b = v.begin(), e = v.end();
    while (b != e) {
        cout << (*b) << " ";
        b++;
    }
    cout << endl;
}

void print(list<int> l) {
    auto b = l.begin(), e = l.end();
    while (b != e) {
        cout << (*b) << " ";
        b++;
    }
    cout << endl;
}

int main(int argc, char** argv) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    print(begin(ia), end(ia));

    list<int> l(begin(ia), end(ia));
    //rm odds
    list<int>::iterator lb = l.begin();
    while (lb != l.end()) {
        if (*lb % 2) {
            lb = l.erase(lb);  //lb指向被删除元素的下一元素
        } else {
            lb++;
        }
    }
    print(l);

    vector<int> v(begin(ia), end(ia));
    //rm evens
    vector<int>::iterator vb = v.begin();
    while (vb != v.end()) {
        if (not(*vb % 2)) {
            vb = v.erase(vb);
        } else {
            vb++;
        }
    }
    print(v);

}