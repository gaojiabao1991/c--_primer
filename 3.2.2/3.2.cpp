#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  //   string line;
  //   while (getline(cin, line)) {
  //     cout << line << endl;
  //   }

  string word;
  while (cin >> word) {
    cout << word << endl;
  }
}