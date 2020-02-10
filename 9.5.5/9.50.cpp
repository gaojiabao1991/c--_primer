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
    // vector<string> v = {"1", "2", "3"};
    // int sum = 0;
    // for (auto &s : v) {
    //     sum += std::stoi(s);
    // }
    // cout << (sum) << endl;

    vector<string> v = {"1.1", "2.2", "3.3"};
    double sum = 0;
    for (auto &s : v) {
        sum += std::stod(s);
    }
    cout << (sum) << endl;
}