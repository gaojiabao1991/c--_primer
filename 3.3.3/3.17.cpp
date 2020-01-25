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
  string word;
  vector<string> words;
  while (cin >> word) {
    words.push_back(word);
  }

  for (auto &word : words) {
    for (auto &c : word) {
      c = toupper(c);
    }
  }

  for (auto word : words) {
    cout << word << endl;
  }
}

