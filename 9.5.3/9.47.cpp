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
    string s = "ab2c3d7R4E6";
    string numbers = "01234567890";
    string::size_type i = 0;

    //print all number positions
    while ((i = s.find_first_of(numbers, i)) != string::npos) {
        cout << (i) << endl;
        i++;
    }

    cout << endl;
    cout << endl;

    //print all non-number positions
    i = 0;
    while ((i = s.find_first_not_of(numbers, i)) != string::npos) {
        cout << (i) << endl;
        i++;
    }
}