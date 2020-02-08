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

vector<int>::iterator find(vector<int>::iterator start, vector<int>::iterator end, int v) {
    while (start != end) {
        if (*start == v) {
            return start;
        }
        start++;
    }
    return end;
}

int main(int argc, char **argv) {
    vector<int> a = {1, 2, 3, 4, 5};
    cout << *(find(a.begin(), a.end(), 3)) << endl;
    cout << *(find(a.begin(), a.end(), 6)) << endl;
}