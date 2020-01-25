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

  for (auto i = v.begin(); i != v.end() && !i->empty(); i++) {
    string &line = *i;
    for (auto j = line.begin(); j != line.end(); j++) {
      *j = toupper(*j);
    }
  }

  for (auto i = v.cbegin(); i != v.cend() && !i->empty(); i++) {
    cout << *i << endl;
  }
}