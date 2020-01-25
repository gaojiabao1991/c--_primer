#include <iostream>
int main()
{
    int v=1;
    std::cout << v <<std::endl; //1

    int *p=&v;
    std::cout << p <<std::endl; // addr
    std::cout << *p <<std::endl;  //1

    v=2;
    std::cout << *p <<std::endl; //2

    *p=3;
    std::cout << v <<std::endl; //3
}