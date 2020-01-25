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
  // vector<int> v; //v1
//   vector<int> v(10); //v2

    // vector<int> v(10,42); //v3

    // vector<int> v{10}; //v4

    // vector<int> v{10,42}; //v5

    // vector<string> v{10}; //v6

    vector<string> v{10,"hi"}; //v7

  vector<int>::size_type size = v.size();
  cout << size << endl;
  if (size > 0) {
    for (auto e : v) {
      cout << e << endl;
    }
  }
}