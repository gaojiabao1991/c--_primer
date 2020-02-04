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

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multi(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

using FN_TYPE = decltype(fn);
int main(int argc, char **argv) {
    vector<FN_TYPE *> vec;
    vec.push_back(&add);
    vec.push_back(&minus);
    vec.push_back(&multi);
    vec.push_back(&divide);

    int a = 2;
    int b = 1;
    for (auto fn : vec) {
        cout << (fn(a, b)) << endl;
    }
}