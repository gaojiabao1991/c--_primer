#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
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

void print(const string msg, vector<string>& v) {
    cout << (msg) << " ";
    cout << "(" << v.size() << ")";
    for (auto& s : v) {
        cout << (s) << " ";
    }
    cout << endl;
}

void dedup(vector<string>& v) {
    std::sort(v.begin(), v.end());
    print("sorted: ", v);
    vector<string>::iterator after = std::unique(v.begin(), v.end());
    print("unique: ", v);
    v.erase(after, v.end());
    print("erase: ", v);
}

int main(int argc, char** argv) {
    vector<string> v = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    dedup(v);
}