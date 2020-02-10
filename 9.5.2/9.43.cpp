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

bool part_equals(const string& s, const string& ov, string::iterator p) {
    for (int i = 0; i < ov.size(); i++) {
        if (*(p + i) != ov[i]) {
            return false;
        }
    }
    return true;
}

void replace(string& s, const string& ov, const string& nv) {
    auto sb = s.begin();
    auto ovb = ov.begin();

    while (sb != s.end()) {
        if (part_equals(s, ov, sb)) {
            sb = s.erase(sb, sb + ov.size());
            sb = s.insert(sb, nv.begin(), nv.end());
            sb += nv.size();
        } else {
            sb++;
        }
    }
}

int main(int argc, char** argv) {
    string s = "how to program java better";
    cout << (s) << endl;
    replace(s, "java", "c++");
    cout << (s) << endl;
}