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
 * 反思1: 记得类成员变量要手动初始化值!!! java中类成员变量会自动初始化, c++不会, 总是忘记初始化, 应该是java写习惯了, 要注意
 * 反思2: 重写方法的时候记得加override关键字, 这个就相当于java的override注解, 加上了编辑器才帮忙检查重写方法的函数名和参数
 * 列表能不能和父类对应上
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

class Disc_quote : public Quote {
   protected:
    size_t count = 0;
    double discount = 0.0;

   public:
    Disc_quote() = default;
    Disc_quote(const string& isbn, double price, size_t count, double discount)
        : Quote(isbn, price), count(count), discount(discount) {}

    double net_price(size_t n) const = 0;  //纯虚函数, 有纯虚函数的类不能初始化
};

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& isbn, double price, size_t count, double discount)
        : Disc_quote(isbn, price, count, discount) {}

    double net_price(size_t n) const override {
        if (n >= count) {
            return price * n * (1 - discount);
        } else {
            return price * n;
        }
    }
};

class Limit_quote : public Disc_quote {
   public:
    Limit_quote() = default;
    Limit_quote(const string& isbn, double price, size_t count, double discount)
        : Disc_quote(isbn, price, count, discount) {}

    double net_price(size_t n) const override {
        if (n <= count) {
            return price * n * (1 - discount);
        } else {
            return price * count * (1 - discount) + price * (n - count);
        }
    }
};