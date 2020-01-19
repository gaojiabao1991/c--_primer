#include <iostream>

int main()
{
    std::cout << "input a&b" << std::endl;
    int a = 0, b = 0;
    std::cin >> a >> b;
    int c = a + b;
    // std::cout << "the sum of " << a << "&" << b << "is" << c << std::endl;
    std::cout << "the sum of ";
    std::cout << a;
    std::cout << " and ";
    std::cout << b;
    std::cout << " is ";
    std::cout << c;
    std::cout << std::endl;

}