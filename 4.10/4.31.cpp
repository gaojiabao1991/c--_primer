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
    vector<int> ivec;
    for (int i = 0; i < 10; ++i) ivec.push_back(0);

    auto cnt = ivec.size();
    for (vector<int>::size_type i = 0; i != ivec.size(); i++, cnt--) {
        ivec[i] = cnt;
    }

    for(auto &i : ivec){
        cout << (i) <<endl;
    }
}