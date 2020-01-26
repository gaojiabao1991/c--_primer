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
  char a[] = "abd";
  char b[] = "abe";

  int cmp = strcmp(a, b);

  if (cmp == 0) {
    cout << "eq" << endl;
  } else if (cmp > 0) {
    cout << "lg" << endl;
  } else {
    cout << "sm" << endl;
  }
}