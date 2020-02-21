#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using std::pair;
using std::multimap;
using std::multiset;
using std::map;
using std::set;
using std::unordered_map;
using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;
using std::ends;
using std::cerr;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::forward_list;
using std::array;
using std::begin;
using std::end;
using std::initializer_list;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::unique;
using std::copy;
using std::back_inserter;
using std::front_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::find;
using namespace std::placeholders;

void translate(ifstream& rules_ifs, ifstream& text_ifs);
unordered_map<string, string> build_rules(ifstream& rules_ifs);
string translate_word(string& s, unordered_map<string, string>& rules);

void translate(ifstream& rules_ifs, ifstream& text_ifs) {
    unordered_map<string, string> rules = build_rules(rules_ifs);
    string line;
    while (getline(text_ifs, line)) {
        istringstream line_s(line);
        string word;
        bool first;
        while (line_s >> word) {
            if (not first) {
                cout << " ";
            } else {
                first = true;
            }

            cout << (translate_word(word, rules));
        }
        cout << endl;
    }
}

unordered_map<string, string> build_rules(ifstream& rules_ifs) {
    unordered_map<string, string> r;
    string k;
    string v;
    while (rules_ifs >> k && getline(rules_ifs, v)) {
        if (v.size() > 1) {
            r[k] = v.substr(1);
        } else {
            throw std::runtime_error("no rule for key: " + k);
        }

        // r.insert({k, v.substr(1)}); //没有影响
    }

    // for (auto& p : r) {
    //     cout << (p.first) << " " << (p.second) << endl;
    // }
    return r;
}

string translate_word(string& s, unordered_map<string, string>& rules) {
    auto it = rules.find(s);
    if (it != rules.end()) {
        return it->second;
    } else {
        return s;
    }
}

int main(int argc, char** argv) {
    ifstream rules_ifs("rules");
    ifstream text_ifs("text");
    translate(rules_ifs, text_ifs);
}