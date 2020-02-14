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
#include <utility>
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
using std::pair;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

int main(int argc, char **argv) {
    map<string, vector<pair<string, int>>> famis;
    vector<pair<string, int>> gao = {{"Gao1", 1952}, {"Gao2", 1987}, {"Gao3", 1991}};
    vector<pair<string, int>> li = {{"Li1", 1952}, {"Li2", 1987}, {"Li3", 1991}};
    famis["Gao"] = gao;
    famis["Li"] = li;

    for (auto &fami : famis) {
        cout << "=====" << (fami.first) << "=====" << endl;
        for (auto &person : fami.second) {
            cout << (person.first) << " " << (person.second) << endl;
        }
    }
}
