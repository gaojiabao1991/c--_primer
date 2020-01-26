#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::vector;

int main() {
  int a[] = {1, 2, 3};
  int b[] = {1, 2, 3};

  auto lenA = end(a) - begin(a);
  auto lenB = end(b) - begin(b);

  if (lenA != lenB) {
    cout << "not equals" << endl;
  } else {
    int *ptA = begin(a);
    int *ptB = begin(b);

    while (ptA < end(a)) {
      if (*ptA != *ptB) {
        cout << "not equals" << endl;
        return 0;
      }

      ptA++;
      ptB++;
    }

    cout << "equals" << endl;
  }
}