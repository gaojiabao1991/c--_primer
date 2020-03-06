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
#include "Quote.h"

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

/**
 * 反思:
 * 1. 容器里如果要存父类,子类, 要存成指针形式后面才能多态调用
 * 2. 存指针的时候最好存成shared_ptr, 这样不用担心存入的对象离开其作用域代码块后就被销毁了从而导致后面调用vector发生错误
 * 3. 方法内的局部变量记得要手动初始化值, 不初始化编译器也不报错, 但是值会是未定义, 可能会出现非常奇怪的结果
 **/

void sum1() {
    vector<Quote> vec;
    vec.push_back(Quote("1", 50));
    vec.push_back(Bulk_quote("2", 50, 10, 0.5));

    double sum = 0;
    for (auto &q : vec) {
        sum += q.net_price(10);
    }

    cout << (sum) << endl;  //1000
}

void sum2() {
    vector<shared_ptr<Quote> > vec;
    vec.push_back(make_shared<Quote>(Quote("1", 50)));
    vec.push_back(make_shared<Bulk_quote>(Bulk_quote("2", 50, 10, 0.5)));

    double sum = 0;
    for (auto &q : vec) {
        sum += q->net_price(10);
    }

    cout << (sum) << endl;  //750
}

int main(int argc, char **argv) {
    sum1();
    sum2();
}