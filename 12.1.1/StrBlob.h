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

class StrBlob {
   public:
    using size_type = vector<string>::size_type;

    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string& s) { data->push_back(s); }
    void pop_back() { data->pop_back(); }

    string& back() {
        check();
        return data->back();
    }

    const string& back() const {
        check();
        return data->back();
    }

    string& front() {
        check();
        return data->front();
    }

    const string& front() const {
        check();
        return data->front();
    }

   private:
    void check() const {
        if (data->empty()) {
            throw std::out_of_range("data is empty");
        }
    }
    shared_ptr<vector<string>> data;
};