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

int fn(int a, int b);

int fn(int a, int b) {
    return a + b;
}

using FN_TYPE = decltype(fn);

int main(int argc, char **argv) {
    vector<FN_TYPE *> vec;
    vec.push_back(&fn);
    vec.push_back(&fn);
    vec.push_back(&fn);
    cout << (vec.size()) << endl;
}