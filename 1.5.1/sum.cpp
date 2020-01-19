#include <iostream>
#include "Sales_item.h"
int main() {
  Sales_item pre, cur;
  if (std::cin >> pre) {
    while (std::cin >> cur) {
      pre += cur;
    }
    std::cout << pre << std::endl;
  }
}