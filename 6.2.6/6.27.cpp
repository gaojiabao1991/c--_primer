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

int sum(initializer_list<int> nums) {
    int sum = 0;
    for (auto &i : nums) {
        sum += i;
    }
    return sum;
}

int main(int argc, char **argv) {
    cout << (sum({1, 2, 3, 4, 5})) << endl;
}