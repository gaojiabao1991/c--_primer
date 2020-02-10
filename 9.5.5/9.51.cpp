#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
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
using std::string;
using std::vector;

class Calendar {
   public:
    Calendar(int year, int month, int date) : year(year), month(month), date(date) {}
    Calendar(string s) {
        // 2020/2/10
        auto p1 = s.find_first_of('/');
        auto p2 = s.find_last_of('/');

        year = std::stoi(s.substr(0, p1));
        month = std::stoi(s.substr(p1 + 1, p2 - p1));
        date = std::stoi(s.substr(p2 + 1, s.size() - p2));
    }

    void print() {
        cout << year << " " << month << " " << date << endl;
    }

   private:
    int year;
    int month;
    int date;
};

int main(int argc, char** argv) {
    Calendar cal("2020/2/10");
    cal.print();
}
