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

bool str_subrange(const string &str1, const string &str2) {
    if (str1.size() == str2.size()) return str1 == str2;

    auto size = str1.size() < str2.size() ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; i++) {
        // if (str1[i] != str2[i]) return;
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    cout << (str_subrange("abc", "abcd")) << endl;
}