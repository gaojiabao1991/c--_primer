#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "Window_mgr.h"

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
    Screen s(5, 5, '.');
    Window_mgr mgr(s);
    mgr.get(0).display(cout);
    mgr.clear(0);
    mgr.get(0).display(cout);
    
}