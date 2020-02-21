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
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using namespace std::placeholders;

shared_ptr<vector<int>> create() {
    // return new vector<int>();
    return make_shared<vector<int>>();
}

void read(istream& is, shared_ptr<vector<int>> vec) {
    int i;
    while (is >> i) {
        vec->push_back(i);
    }
}

void print(ostream& os, shared_ptr<vector<int>> vec) {
    for (auto& i : *vec) {
        cout << (i) << endl;
    }
}

void process() {
    shared_ptr<vector<int>> p_vec = create();
    read(cin, p_vec);
    print(cout, p_vec);
}

int main(int argc, char** argv) {
    process();
}