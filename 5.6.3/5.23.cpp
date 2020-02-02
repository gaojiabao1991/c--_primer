#include <cstring>
#include <iostream>
#include <string>
#include <vector>
// #include <stdexcept>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::runtime_error;
using std::string;
using std::vector;

int main() {
    while (true) {
        try {
            cout << ("input two number") << endl;
            int a, b;
            cin >> a >> b;
            if (b == 0) {
                throw runtime_error("error: /0");
            }
            cout << (a / b) << endl;
        } catch (runtime_error e) {
            std::cerr << e.what() << '\n';
            cout << ("input again?") << endl;
            string ans;
            cin >> ans;
            if (ans == "" || ans[0] == 'n') break;
        }
    }
}