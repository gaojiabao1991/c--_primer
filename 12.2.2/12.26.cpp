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

void origin() {
    int n = 20;
    string* const p = new string[n];
    string s;
    string* q = p;
    while (cin >> s && q != p + n) {
        *q++ = s;
    }
    const size_t sz = q - p;
    for (int i = 0; i < sz; i++) {
        cout << *(p + i) << endl;
    }

    delete[] p;
}
void with_alloc() {
    int n = 20;
    allocator<string> alloc;
    string* const b = alloc.allocate(n);

    string* cur = b;

    string s;
    while (cin >> s && cur != b + n) {
        alloc.construct(cur++, s);
    }

    const size_t sz = cur - b;
    // use
    for (int i = 0; i < sz; i++) {
        cout << *(b + i) << endl;
    }

    // delete: 1. destory objs; 2: free memory
    for (int i = 0; i < sz; i++) {
        alloc.destroy(b + i);
    }

    alloc.deallocate(b, n);
}

int main(int argc, char** argv) {
    // origin();
    with_alloc();
}