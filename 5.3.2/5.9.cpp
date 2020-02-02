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
    char c;

    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while (cin >> c) {
        switch (c) {
            case 'a':
            case 'A':
                aCnt++;
                break;
            case 'e':
            case 'E':
                eCnt++;
                break;

            case 'i':
            case 'I':
                iCnt++;
                break;

            case 'o':
            case 'O':
                oCnt++;
                break;

            case 'u':
            case 'U':
                uCnt++;
                break;
        }

        // if (c == 'a') {
        //     aCnt++;
        // } else if (c == 'e') {
        //     eCnt++;
        // } else if (c == 'i') {
        //     iCnt++;
        // } else if (c == 'o') {
        //     oCnt++;
        // } else if (c == 'u') {
        //     uCnt++;
        // }
    }

    cout << ("aCnt -> ") << aCnt << endl;
    cout << ("eCnt -> ") << eCnt << endl;
    cout << ("iCnt -> ") << iCnt << endl;
    cout << ("oCnt -> ") << oCnt << endl;
    cout << ("uCnt -> ") << uCnt << endl;
}