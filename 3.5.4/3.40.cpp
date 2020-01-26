#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  char a[] = "hello";
  char b[] = "world";

  char c[10];

  strcpy(c, a);
  strcat(c, b);

  cout << c << endl;

}