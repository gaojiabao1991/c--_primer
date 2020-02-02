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
using std::string;
using std::vector;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    for (auto &e : v) {
        // cout << e <<endl;
        e = e % 2 == 0 ? e : e * e;
    }

    for(auto &e:v){
        cout << e <<endl;
    }
}