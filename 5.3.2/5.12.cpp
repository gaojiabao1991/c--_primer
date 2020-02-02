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
    int ffCount = 0, flCount = 0, fiCount = 0;
    string line;
    while (getline(cin, line)) {
        cout << (line) << endl;
        for (int i = 0; i < static_cast<int>(line.size()) - 1; i++) {
            if (line[i] == 'f') {
                switch (line[i + 1]) {
                    case 'f':
                        ffCount++;
                        break;

                    case 'l':
                        flCount++;
                        break;

                    case 'i':
                        fiCount++;
                        break;

                    default:
                        break;
                }
            }
        }
    }

    cout << ("ffCount -> ") << ffCount << endl;
    cout << ("flCount -> ") << flCount << endl;
    cout << ("fiCount -> ") << fiCount << endl;
}