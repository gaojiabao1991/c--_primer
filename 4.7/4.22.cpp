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
    int grade;
    while (cin >> grade) {
        // string finalGrade = grade > 90 ? "high pass" : grade > 75 ? "pass" : grade > 60 ? "low pass" : "fail";
        // cout << finalGrade <<endl;9

        string finalGrade;
        if (grade > 90) {
            finalGrade = "high pass";
        } else if (grade > 75) {
            finalGrade = "pass";
        } else if (grade > 60) {
            finalGrade = "low pass";
        } else {
            finalGrade = "fail";
        }

        cout << finalGrade << endl;
    }
}