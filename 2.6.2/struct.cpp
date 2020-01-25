#include <iostream>
#include <string>
#include "Sales_data.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main() {
  string isbn = "";
  unsigned int sold = 0;
  double price = 0;

  Sales_data sum;
  while (cin >> isbn >> sold >> price) {
    cout << isbn << " " << sold << " " << price << endl;
    if (sum.isbn == "") sum.isbn = isbn;

    if (sum.isbn == isbn) {
      sum.sold += sold;
      sum.revenue += price * sold;
    } else {
      cerr << "error, diff isbn";
      return -1;
    }
  }

  cout << "isbn: " << sum.isbn << ", sold: " << sum.sold
            << ", revenue: " << sum.revenue
            << ", avgPrice: " << sum.revenue / sum.sold << endl;
}
