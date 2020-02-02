#include <cstring>
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
  int ia[3][4];
  int i = 0;
  for (auto &row : ia) {
    for (auto &e : row) {
      e = i;
      i++;
    }
  }

  for (int(&row)[4] : ia) {
    for (int e : row) cout << e << endl;
  }

  //   for (int i = 0; i < 3; i++) {
  //     for (int j = 0; j < 4; j++) cout << ia[i][j] << endl;
  //   }

  //   for (int(*p)[4] = ia; p < ia + 3; p++) {
  //     for (int *q = *p; q < *p + 4; q++) cout << *q << endl;
  //   }
}