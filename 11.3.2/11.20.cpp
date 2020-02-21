#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::back_inserter;
using std::begin;
using std::cerr;
using std::cin;
using std::copy;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::forward_list;
using std::front_inserter;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::map;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

void to_alnum(string &word) {
    //只保留数字字幕
    auto end = std::remove_if(word.begin(), word.end(), [](char c) { return not isalnum(c); });
    //to lower case
    for (auto &c : word) {
        c = tolower(c);
    }
    word.erase(end, word.end());
}

int main(int argc, char **argv) {
    set<string> excludes = {"include"};

    map<string, size_t> m;
    string word;
    while (cin >> word) {
        to_alnum(word);

        if (word.size() == 0 or excludes.find(word) != excludes.end()) continue;
        // m[word]++;
        auto ret = m.insert({word, 1});
        if (!ret.second) {
            ret.first->second++;
        }
    }
    for (auto &w : m) {
        cout << (w.first) << " " << w.second << endl;
    }
}