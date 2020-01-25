#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(line);
  }

  for (auto line : v) {
    cout << line << endl;
  }
}