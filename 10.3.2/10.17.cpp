#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::string;
using std::vector;

class Sales_data {
   public:
    Sales_data(string isbn) : isbn(isbn) {}
    string isbn;
};

// bool compareIsbn(Sales_data& a, Sales_data& b) {
//     return a.isbn < b.isbn;
// }

int main(int argc, char** argv) {
    vector<Sales_data> v = {Sales_data("456"),
                            Sales_data("789"),
                            Sales_data("123")};
    sort(v.begin(), v.end(), [](Sales_data& a, Sales_data& b) { return a.isbn < b.isbn; });
    for (auto& sd : v) {
        cout << (sd.isbn) << endl;
    }
}
