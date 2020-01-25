#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string a;
  string b;

  cin >> a;
  cin >> b;

  if (a.size() == b.size()) {
    cout << "equals" << endl;
  } else {
    string larger;
    if (a.size() > b.size()) {
      larger = a;
    } else {
      larger = b;
    }
    cout << "larger: " << larger << endl;
  }
}