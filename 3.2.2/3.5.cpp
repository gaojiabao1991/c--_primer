#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string word;
  string join;
  while (cin >> word) {
    join += word+" ";
  }
  cout << join << endl;
}