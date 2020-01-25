#include <iostream>
int main()
{
    int i = 42;
    int *p;
    int *&r = p;

    r=&i;
    std::cout << *r <<std::endl;
    std::cout << *p <<std::endl;

    *r=0;
    std::cout << i <<std::endl;
    std::cout << *p <<std::endl;

}