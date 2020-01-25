#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string s = "ab,c.d";
  string r = "";
  for (auto &c : s) {
    if (!ispunct(c)) {
      r += c;
    }
  }

  cout << s << endl;
  cout << r << endl;
}