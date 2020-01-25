#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "input min & max" << endl;
  int min, max;
  cin >> min >> max;

  while (min <= max) {
    cout << min<<endl;
    min++;
  }
}
