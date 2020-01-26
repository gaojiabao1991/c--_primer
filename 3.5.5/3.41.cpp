#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};

  vector<int> b(a, end(a));
  //   for (auto e : b) cout << e << endl;

  int c[6];
  for (int i = 0; i < 6; i++) c[i] = b[i];

  for (auto e : c) cout << e << endl;
}