#include <iostream>
int main()
{
    std::cout << "input some numbers, and end with the key e" << std::endl;
    int sum = 0, a = 0;
    while (std::cin >> a)
    {
        sum += a;
    }
    std::cout << "sum: " << sum << std::endl;
}
