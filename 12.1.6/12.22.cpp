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
#include "StrBlob.h"

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

int main(int argc, char **argv) {
    const StrBlob blob({"a", "b", "c", "d", "e"});
    // while (blob.size() > 0) {
    //     cout << (blob.back()) << endl;
    //     blob.pop_back();
    // }

    StrBlobPtr b = blob.begin();
    for (int i = 0; i < blob.size(); i++) {
        b.deref() = "x";
        b.inc();
    }

    StrBlobPtr b2 = blob.begin();
    for (int i = 0; i < blob.size(); i++) {
        cout << (b2.deref()) << endl;
        b2.inc();
    }
}