#include <iostream>

int main()
{
    std::cout << "输入min&max" << std::endl;
    int min = 0, max = 0;
    std::cin >> min >> max;

    while (min <= max)
    {
        std::cout << min << std::endl;
        min++;
    }
}