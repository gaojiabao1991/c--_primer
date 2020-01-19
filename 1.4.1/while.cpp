#include <iostream>
int main(int argc, char const *argv[])
{
    int a = 50, sum = 0;
    while (a <= 100)
    {
        sum += a;
        a++;
    }

    std::cout << "sum: " << sum << std::endl;
}
