#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    string buf;

    string last = "";
    while (cin >> buf && !buf.empty()) {
        if (last == "") {
            last = buf;
            continue;
        }

        if (buf == last) {
            cout << ("get repeat: ") << buf << endl;
            break;
        } else {
            last = buf;
            continue;
        }
    }

    cout << ("no repeat") << endl;
}