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

class CheckLen {
    int l;

   public:
    CheckLen(int len) { l = len; }
    bool operator()(const string& s) {
        return s.size() == l;
    }
};

int main(int argc, char** argv) {
    vector<CheckLen> checkers;
    vector<int> count;
    for (int i = 0; i < 10; i++) {
        checkers.push_back(CheckLen(i + 1));
        count.push_back(0);
    }

    ifstream ifs("14.38.cpp");
    string word;
    while (ifs >> word) {
        for (int i = 0; i < 10; i++) {
            if (checkers[i](word)) {
                count[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < count.size(); i++) {
        cout << ("len: ") << i + 1 << " , count: " << count[i] << endl;
    }
}