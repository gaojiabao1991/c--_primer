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

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return ctr > 1 ? word + ending : word;
}

int main(int argc, char **argv) {
    // cout << make_plural(2, "abc", "s") << endl;
    cout << make_plural(2, "abc") << endl;
}