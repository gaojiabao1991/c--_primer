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

void print_vec(vector<int> vec, int idx) {
#ifndef NDEBUG
    cout << ("cur idx: ") << idx << endl;
#endif

    if (idx == vec.size()) return;
    cout << (vec[idx]) << endl;
    print_vec(vec, idx + 1);
}

int main(int argc, char **argv) {
    vector<int> vec = {1, 2, 3, 4, 5};
    print_vec(vec, 0);
}