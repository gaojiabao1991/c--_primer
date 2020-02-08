#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Example.h"

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

int main(int argc, char **argv) {
    //Account
    cout << (Account::interestRate) << endl;
    Account::setRate(3.0);
    cout << (Account::interestRate) << endl;

    //Example
    cout << (Example::rate) << endl;
    for (auto &d : Example::vec) {
        cout << (d) << endl;
    }
}