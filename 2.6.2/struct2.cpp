#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main() {
  string isbn = "";
  unsigned int sold = 0;
  double price = 0;

  int recordNum = 0;
  string lastIsbn = "";

  while (cin >> isbn >> sold >> price) {
    // ::cout << isbn << " " << sold << " " << price << ::endl;
    if (lastIsbn == "") lastIsbn == isbn;

    if (lastIsbn == isbn) {
      recordNum++;
    } else {
      cout << lastIsbn << " : " << recordNum << endl;
      lastIsbn = isbn;
      recordNum = 1;
    }
    
  }
  cout << lastIsbn << " : " << recordNum << endl;
}
