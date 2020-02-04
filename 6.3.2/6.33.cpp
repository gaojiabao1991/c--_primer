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

void printVec(vector<int> vec, int idx) {
    if (idx == vec.size()) return;
    cout << (vec[idx]) << endl;
    printVec(vec, idx + 1);
}

int main(int argc, char **argv) {
    vector<int> vec = {1, 2, 3, 4, 5};
    printVec(vec, 0);
}