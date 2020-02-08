#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Account {
   public:
    static double interestRate;
    static void setRate(double rate) { interestRate = rate; }
    static double getRate() { return interestRate; }

   private:
    string owner;
    double amount;
};

double Account::interestRate = 2.0;
