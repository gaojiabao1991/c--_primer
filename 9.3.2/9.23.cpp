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

int main(int argc, char** argv) {
    vector<int> v = {};

    try {
        cout << (v.at(0)) << endl;  //raise catchable exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // cout << (v[0]) << endl; // Segmentation fault (core dumped)
    // cout << (v.front()) << endl; //Segmentation fault (core dumped)
    cout << (*(v.begin())) << endl;  //Segmentation fault (core dumped)
}