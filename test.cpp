#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string sa[10];
int ia[10];

int main() {
  int ia[3][4];

  int i = 0;
  for (auto &row : ia) {
    for (auto &e : row) {
      e = i;
      i++;
    }
  }

  for (auto &row : ia) {
    for (auto e : row) {
      cout << e << endl;
    }
  }

  // int(*p)[4] = ia;
  // cout << (*p)[2] << endl;
  // cout << *ia <<endl;

  int(*p)[4] = &ia[2];
  cout << (*p)[0] << endl;
}