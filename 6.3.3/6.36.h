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
using std::string;
using std::vector;

string (*func1())[10];

using arr10 = string[10];
arr10 *func2();

auto func3() -> string (*)[10];

string tmp[10] = {};
decltype(tmp) *func4();
