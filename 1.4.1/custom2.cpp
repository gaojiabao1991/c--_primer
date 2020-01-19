#include <iostream>

int main() {
  std::cout << "输入range: num1 & num2" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;

  int min = 0, max = 0;
  if (num1 >= num2) {
    max = num1;
    min = num2;
  } else {
    min = num1;
    max = num2;
  }

  while (min <= max) {
    std::cout << min << std::endl;
    min++;
  }
}