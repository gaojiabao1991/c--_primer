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
  vector<int> v;
  for (int i = 1; i < 11; i++) {
    v.push_back(i);
  }

  for (auto it = v.begin(); it != v.end(); it++) {
    *it *= 2;
  }

  for (auto i : v) cout << i << endl;
}