#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main()
{
    const string s="Hello World";
    for(auto &c : s){
        cout << c <<endl;
    }
}