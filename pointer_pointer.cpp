#include <iostream>

int main() {
  int v = 1024;
  int *p = &v;
  int **pp = &p;

  std::cout << v << std::endl;
  std::cout << *p << std::endl;
  std::cout << **pp << std::endl;
}