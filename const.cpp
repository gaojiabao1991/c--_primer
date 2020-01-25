#include "const.h"
#include <iostream>

extern const int bufSize;
extern int v;

int main() {
  //   std::cout << bufSize << std::endl;
  //   std::cout << v << std::endl;

  //   int i = 42;

  //   const int &c = i;
  //   std::cout << c << std::endl;

  //   i = 0;
  //   std::cout << c << std::endl;

  //   int i = -1, &r = 0;

  //   int i = -1;
  //   int i2 = 1;
  //   int *const p2 = &i2;

  //   const int i = -1, &r = 0;

  //   const int *const p3 = &i2;

  //   const int *p1 = &i2;

  //   const int &const r2;

  int i = -1;
  const int i2 = i, &r = i;

  std::cout << "a" <<std::endl;
}