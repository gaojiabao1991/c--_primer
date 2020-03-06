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

/**
 * 反思: price需要手动初始化, c++为了节约性能, 对于未使用的内置类型, 初始值是未定义的
 **/

class Quote {
    string isbn;

   public:
    Quote() = default;
    Quote(const string& isbn, double price) : isbn(isbn), price(price) {}
    virtual ~Quote() = default;

    string get_isbn() const {
        return isbn;
    }

    virtual double net_price(size_t n) const {
        return price * n;
    }

   protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
    size_t min_qty = 0;
    double discount = 0.0;

   public:
    Bulk_quote() = default;
    Bulk_quote(const string& isbn, double price, size_t min_qty, double discount)
        : Quote(isbn, price), min_qty(min_qty), discount(discount) {}

    double net_price(size_t n) const override {
        if (n >= min_qty) {
            return (1 - discount) * price * n;
        } else {
            return price * n;
        }
    }
};

class Limit_quote : public Quote {
    size_t max_qty = 0;
    double discount = 0.0;

   public:
    Limit_quote() = default;
    Limit_quote(const string& isbn, double price, size_t max_qty, double discount)
        : Quote(isbn, price), max_qty(max_qty), discount(discount) {}

    double net_price(size_t n) const override {
        if (n < max_qty) {
            return (1 - discount) * price * n;
        } else {
            return price * n;
        }
    }
};
