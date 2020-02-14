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
#include <stdexcept>
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
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::runtime_error;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

void process(vector<string>& sv, vector<int>& iv, vector<pair<string, int>>& pv) {
    if (sv.size() != iv.size()) {
        throw runtime_error("illegal args");
    }

    for (int i = 0; i < sv.size(); i++) {
        // pv.push_back(pair<string, int>(sv[i], iv[i]));
        // pv.push_back(std::make_pair(sv[i], iv[i]));
        pv.push_back({sv[i], iv[i]});
    }
}

int main(int argc, char** argv) {
    vector<string> sv = {"a", "b", "c"};
    vector<int> iv = {1, 2, 3};
    vector<pair<string, int>> pv;

    process(sv, iv, pv);

    for (auto& p : pv) {
        cout << (p.first) << " " << (p.second) << endl;
    }
}