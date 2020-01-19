#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "input min& max" << std::endl;
    int min = 0, max = 0;
    std::cin >> min >> max;

    for (int i = min; i <= max; i++)
    {
        std::cout << i << std::endl;
    }
}
