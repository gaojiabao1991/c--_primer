#include <iostream>
#include "Sales_item.h"
int main() {
  Sales_item pre;
  if (std::cin >> pre) {
    Sales_item cur;
    while (std::cin >> cur) {
      if (cur.isbn() == pre.isbn()) {
        pre += cur;
      } else {
        std::cout << pre << std::endl;
        pre = cur;
      }
    }
    std::cout << pre << std::endl;
  } else {
    std::cout << "No data. exit" << std::endl;
    return -1;
  }
  return 0;
}