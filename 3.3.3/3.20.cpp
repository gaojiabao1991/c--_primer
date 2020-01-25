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
  int i;
  while (cin >> i) {
    v.push_back(i);
  }

  //   for (decltype(v.size()) i = 0; i < v.size(); i++) {
  //     if (i % 2 == 1) {
  //       cout << v[i] + v[i - 1] << endl;
  //     }
  //   }

  for (decltype(v.size()) i = 0; i < v.size(); i++) {
    int mirror = v.size() - 1 - i;
    if (mirror > i) {
      cout << v[i] + v[mirror] << endl;
    }
  }
}