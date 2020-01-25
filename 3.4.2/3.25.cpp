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
  vector<int> v(11, 0);
  int score;
  while (cin >> score) {
    (*(v.begin() + score / 10))++;
  }

  for (auto s : v) cout << s << endl;
}