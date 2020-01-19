#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item pre, cur;
  if (std::cin >> pre) {
    int cnt = 1;
    while (std::cin >> cur) {
      if (cur.isbn() == pre.isbn()) {
        cnt++;
      } else {
        std::cout << "book " << pre.isbn() << " count: " << cnt << std::endl;
        pre = cur;
        cnt = 1;
      }
    }
    std::cout << "book " << pre.isbn() << " count: " << cnt << std::endl;
  }
}