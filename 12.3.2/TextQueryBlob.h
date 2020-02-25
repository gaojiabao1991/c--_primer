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
#include "StrBlob.h"

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
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::weak_ptr;
using namespace std::placeholders;

class QueryResult {
   public:
    QueryResult(shared_ptr<set<int>> idx, StrBlob lines) : idx(idx), lines(lines) {}
    void print();

   private:
    const shared_ptr<set<int>> idx;
    const StrBlob lines;
};

void QueryResult::print() {
    if (idx->size() == 0) {
        cout << ("not found") << endl;
        return;
    }

    cout << ("occurs ") << idx->size() << " times" << endl;

    int show_num = 0;
    const int max_show = 5;
    for (auto& i : *idx) {
        auto b = lines.begin();
        string line = b.advance(i).deref();
        cout << show_num + 1 << ") line " << (i + 1) << " , " << line << endl;
        if (++show_num == max_show) {
            break;
        }
    }

    if (show_num == max_show && idx->size() > max_show) {
        cout << (idx->size() - max_show) << " more to show..." << endl;
    }
}

class TextQuery {
   public:
    TextQuery(ifstream& ifs);

    QueryResult query(string word);

   private:
    // shared_ptr<vector<string>> lines;
    StrBlob lines;

    map<string, shared_ptr<set<int>>> word2lines;
};
TextQuery::TextQuery(ifstream& ifs) {
    string line;
    int idx = 0;
    while (std::getline(ifs, line)) {
        lines.push_back(line);
        std::stringstream ss(line);
        string word;
        while (ss >> word) {
            // auto p = word2lines.find(word);
            // if (p == word2lines.end()) {
            //     word2lines[word] = shared_ptr<set<int>>(new set<int>());
            // }
            // (*word2lines[word]).insert(idx);

            shared_ptr<set<int>>& idx_pt = word2lines[lower_str(word)];
            if (!idx_pt) {
                idx_pt.reset(new set<int>());
            }
            idx_pt->insert(idx);
        }
        idx++;
    }
}

QueryResult TextQuery::query(const string word) {
    static shared_ptr<set<int>> empty_ptr(new set<int>());

    string lower = word;
    lower_str(lower);
    map<string, shared_ptr<set<int>>>::iterator f = word2lines.find(lower);
    if (f != word2lines.end()) {
        return QueryResult((*f).second, lines);
    } else {
        // return QueryResult(shared_ptr<set<int>>(new set<int>()), lines);
        return QueryResult(empty_ptr, lines);
    }
}
