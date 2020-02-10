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

string combine(const string& name, const string& prefix, const string& postfix) {
    string r = name;
    r.insert(0, prefix);
    r.insert(r.size(), postfix);
    return r;
}

int main(int argc, char** argv) {
    cout << (combine("Gao", "Mr.", "III")) << endl;
}