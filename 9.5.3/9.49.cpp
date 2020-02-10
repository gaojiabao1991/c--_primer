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
    string excludes = "dfpg";
    string maxWord = "";
    string word;
    while (cin >> word) {
        if (word.find_first_of(excludes) == string::npos && word.size() > maxWord.size()) {
            maxWord = word;
        }
    }

    if (maxWord == "") {
        cout << ("no legal word") << endl;
    } else {
        cout << ("max legal word: ") << maxWord << endl;
    }
}