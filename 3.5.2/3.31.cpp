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
  //   int a[10] = {};
  //   for (int i = 0; i < 10; i++) a[i] = i;

  //   for (auto e : a) cout << e << endl;

  //   int b[10] = {};
  //   for (int i = 0; i < 10; i++) {
  //     b[i] = a[i];
  //   }

  //   for (auto e : b) cout << e << endl;

  vector<int> a;
  for (int i = 0; i < 10; i++) a.push_back(i);

  vector<int> b = a;
  for (auto e : b) cout << e << endl;

  *a.begin()=100;

  for (auto e : a) cout << e << endl; 
  for (auto e : b) cout << e << endl;
}