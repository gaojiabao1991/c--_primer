#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string a = "abcd";
  //   for (char &c : a) {
  //     c = 'X';
  //   }

  //   decltype(a.size()) idx = 0;
  //   while (idx < a.size()) {
  //     a[idx] = 'X';
  //     idx++;
  //   }

  for (decltype(a.size()) i = 0; i < a.size(); i++) {
    a[i] = 'X';
  }

  cout << a << endl;
}