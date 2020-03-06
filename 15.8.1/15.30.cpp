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

class Basket {
    static bool compare(const shared_ptr<Quote>& a, const shared_ptr<Quote>& b) { return a->get_isbn() < b->get_isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};

   public:
    void add_item(shared_ptr<Quote> item) {
        items.insert(item);
    }

    void add_item(const Quote& item) {
        items.insert(shared_ptr<Quote>(item.clone()));
    }

    void add_item(Quote&& item) {
        items.insert(shared_ptr<Quote>(item.clone()));
    }

    void print_items() {
        double total = 0;
        for (auto b = items.begin(); b != items.end(); b = items.upper_bound(*b)) {
            size_t count = items.count(*b);
            double net_price = (*b)->net_price(count);
            cout << "isbn: " << ((*b)->get_isbn()) << ", price: " << (*b)->get_price() << ", count: " << count << ", net_price:  " << net_price << endl;
            total += net_price;
        }
        cout << ("total: ") << total << endl;
    }
};

int main(int argc, char** argv) {
    Basket b;
    // b.add_item(shared_ptr<Quote>(new Quote("1", 10)));
    // b.add_item(shared_ptr<Quote>(new Quote("2", 20)));
    // b.add_item(shared_ptr<Quote>(new Bulk_quote("3", 30, 1, 0.5)));
    // b.add_item(shared_ptr<Quote>(new Quote("2", 20)));
    // b.add_item(shared_ptr<Quote>(new Bulk_quote("3", 30, 1, 0.5)));
    // b.add_item(shared_ptr<Quote>(new Bulk_quote("3", 30, 1, 0.5)));

    b.add_item(Quote("1", 10));
    b.add_item(Quote("2", 20));
    b.add_item(Bulk_quote("3", 30, 1, 0.5));
    b.add_item(Quote("2", 20));
    b.add_item(Bulk_quote("3", 30, 1, 0.5));
    b.add_item(Bulk_quote("3", 30, 1, 0.5));

    b.print_items();

    shared_ptr<Quote> c;
    c = shared_ptr<Bulk_quote>(new Bulk_quote("3", 30, 1, 0.5));
}