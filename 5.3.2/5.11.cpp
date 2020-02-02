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
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spaceCnt = 0, tabCnt = 0, lineCnt = 0;

    string line;
    while (getline(cin, line)) {
        lineCnt++;
        for (auto &c : line) {
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

                case ' ':
                    spaceCnt++;
                    break;
                case '\t':
                    tabCnt++;
                    break;
            }
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
    cout << ("spaceCnt -> ") << spaceCnt << endl;
    cout << ("tabCnt -> ") << tabCnt << endl;
    cout << ("lineCnt -> ") << lineCnt << endl;
}