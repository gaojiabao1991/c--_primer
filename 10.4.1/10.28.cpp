#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::begin;
using std::cerr;
using std::cin;
using std::copy;
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
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

void print(const string &msg, deque<int> q) {
    cout << (msg) << ": ";
    for (auto &i : q) {
        cout << (i) << " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < 10; i++) {
        v.push_back(i);
    }

    deque<int> i;
    deque<int> bi;
    deque<int> fi;

    copy(v.begin(), v.end(), std::inserter(i, i.begin()));
    copy(v.begin(), v.end(), std::back_inserter(bi));
    copy(v.begin(), v.end(), std::front_inserter(fi));

    print("i", i);
    print("bi", bi);
    print("fi", fi);
}