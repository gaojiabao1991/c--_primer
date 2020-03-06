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

class ShorterString {
   public:
    bool operator()(const string& a, const string& b) {
        return a.size() < b.size();
    }
};

class LongerThan {
    int limit;

   public:
    LongerThan(int sz) {
        limit = sz;
    }

    bool operator()(const string& a) {
        return a.size() >= limit;
    }
};

vector<string> longer_than(vector<string>& words, vector<string>::size_type sz) {
    // 按字典序排序
    sort(words.begin(), words.end());

    //去重
    auto p_out = unique(words.begin(), words.end());
    words.erase(p_out, words.end());

    //按长度短->长排序, 相同长度的保持字典序
    stable_sort(words.begin(),
                words.end(),
                ShorterString());

    //找到第一个长度>=sz的指针
    auto p_1st_larger = std::find_if(words.begin(), words.end(), LongerThan(sz));

    //将长度>=sz的元素拷贝到一个新的vector里返回
    auto r_sz = words.end() - p_1st_larger;
    vector<string> r(r_sz);
    copy(p_1st_larger, words.end(), r.begin());
    return r;
}

int main(int argc, char** argv) {
    vector<string> v = {"aaa", "b", "c", "c", "bb", "cc", "xx", "xyz", "dd", "a", "bb", "aaa", "bbb"};
    vector<string> r = longer_than(v, 3);
    for (auto& s : r) {
        cout << (s) << endl;
    }
}