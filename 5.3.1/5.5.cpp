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
    //60) F 0
    //[60,70) D 1
    //[70,80) C 2
    //[80,90) B 3
    //[90,100) A 4
    //[100] A++ 5

    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    for (int score = 0; score <= 100; score++) {
        // string txtScore;

        // if (score < 60) {
        //     txtScore = scores[0];
        // } else {
        //     txtScore = scores[(score - 50) / 10];
        // }

        string txtScore = score < 60 ? scores[0] : scores[(score - 50) / 10];

        cout << score << " -> " << (txtScore) << endl;
    }
}