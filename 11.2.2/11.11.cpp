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
#include <vector>
#include "Sales_data.h"

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
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

bool compareIsbn(const Sales_data& a, const Sales_data& b) {
    return a.isbn() < b.isbn();
}

int main(int argc, char** argv) {
    // multiset<Sales_data> bookStore; //runtime error

    // multiset<Sales_data, decltype(compareIsbn)*> bookStore(compareIsbn);  //decltype, OK

    multiset<Sales_data, bool (*)(const Sales_data& a, const Sales_data& b)> bookStore(compareIsbn); //直接声明为函数指针类型, OK

    // using FP = bool (*)(const Sales_data& a, const Sales_data& b); 
    // multiset<Sales_data, FP> bookStore(compareIsbn);  //给函数指针类型起别名 ,OK



    bookStore.insert(Sales_data("123"));
    bookStore.insert(Sales_data("456"));
    bookStore.insert(Sales_data("789"));

    for (auto& sd : bookStore) {
        print(cout, sd);
    }
}