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
#include <memory>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Common.h"

using std::allocator;
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
using std::find;
using std::forward_list;
using std::front_inserter;
using std::getline;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::make_shared;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::runtime_error;
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::stringstream;
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using namespace std::placeholders;

int main(int argc, char **argv) {
    vector<string> lines;
    map<string, set<int>> word2idx;

    ifstream ifs("zane.txt");
    string line;

    int idx = 0;
    while (getline(ifs, line)) {
        lines.push_back(line);
        stringstream ss(line);
        string word;
        while (ss >> word) {
            word2idx[lower_str(word)].insert(idx);
        }
        idx++;
    }

    cout << ("pls input word to search, q to quit") << endl;
    string input;
    while (cin >> input && input != "q") {
        auto p = word2idx.find(lower_str(input));
        if (p != word2idx.end()) {
            set<int> &idx = (*p).second;
            cout << ("occurs: ") << idx.size() << endl;

            int showed = 0;
            int max_show = 5;
            for (auto &i : idx) {
                cout << ("line: ") << i + 1 << "  " << lines[i] << endl;
                if (++showed == max_show) break;
            }

            if (showed == max_show && idx.size() > showed) {
                cout << idx.size() - showed << (" more ...") << endl;
            }

        } else {
            cout << ("not found") << endl;
        }
    }
}
