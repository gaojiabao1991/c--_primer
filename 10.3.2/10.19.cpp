#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using std::array;
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
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;

vector<string> longer_than(vector<string>& words, vector<string>::size_type sz) {
    // 按字典序排序
    sort(words.begin(), words.end());

    //去重
    auto p_out = unique(words.begin(), words.end());
    words.erase(p_out, words.end());

    //找到第一个长度>=sz的指针
    // auto p_1st_larger = std::find_if(words.begin(), words.end(), [sz](const string& s) { return s.size() >= sz; });
    auto p_1st_larger = std::stable_partition(words.begin(), words.end(), [sz](string& word) { return word.size() < sz; });

    // 将长度>=sz的元素拷贝到一个新的vector里返回
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