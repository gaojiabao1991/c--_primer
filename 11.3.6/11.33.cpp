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
using std::find;
using std::forward_list;
using std::front_inserter;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

void translate(ifstream& rules_ifs, ifstream& text_ifs);
map<string, string> build_rules(ifstream& rules_ifs);
string translate_word(string& s, map<string, string>& rules);

void translate(ifstream& rules_ifs, ifstream& text_ifs) {
    map<string, string> rules = build_rules(rules_ifs);
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

map<string, string> build_rules(ifstream& rules_ifs) {
    map<string, string> r;
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

string translate_word(string& s, map<string, string>& rules) {
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