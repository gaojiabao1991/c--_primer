#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"

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
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << ("\n") << endl;
    myScreen.display(cout);
    cout << ("\n") << endl;
}