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

  //   for (auto it = v.begin(); it < v.end(); it += 2) {
  //     if (it != v.end() - 1) {
  //       cout << *it + *(it + 1) << endl;
  //     }
  //   }

  auto mid = v.begin() + v.size() / 2;

  for (auto it = v.begin(); it < mid; it++) {
    cout << *it << " - " << *(v.end() - 1 - (it - v.begin())) << endl;
  }
}