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
    string s;

    string last = "";
    int repeat = 0;
    int maxRepeat = 0;
    string maxWord = "";

    while (cin >> s) {
        if (last == "") {
            last = s;
            repeat = 1;
            continue;
        }
        if (s == last) {
            repeat++;
        } else {
            if (repeat > maxRepeat) {
                maxRepeat = repeat;
                maxWord = last;
            }
            last = s;
            repeat = 1;
        }
    }

    if (repeat > maxRepeat) {
        maxRepeat = repeat;
        maxWord = last;
    }

    if (maxRepeat > 1) {
        cout << ("max repeat word: ") << maxWord << " , repeat time: " << maxRepeat << endl;
    } else {
        cout << ("no repeat word") << endl;
    }
}