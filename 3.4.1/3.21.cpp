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
  vector<string> v{10, "hi"};  // v7

  //   vector<int>::size_type size = v.size();
  //   cout << size << endl;
  //   if (size > 0) {
  //     for (auto e : v) {
  //       cout << e << endl;
  //     }
  //   }

  for (auto i = v.cbegin(); i != v.cend(); i++) {
    cout << *i << endl;
  }
}