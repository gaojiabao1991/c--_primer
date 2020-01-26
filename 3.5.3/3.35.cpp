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
  int a[10] = {};
  for (int i = 0; i < 10; i++) a[i] = i;

  for (int i = 0; i < 10; i++) cout << a[i] << endl;

  for (int *p = a; p < &a[10]; p++) *p = 0;

  for (int i = 0; i < 10; i++) cout << a[i] << endl;
}