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

using pos = string::size_type;
template <pos W, pos H> class Screen;
template <pos W, pos H>
ostream& operator<<(ostream& os, const Screen<W, H>& screen);

template <pos W, pos H>
istream& operator>>(istream& is, const Screen<W, H>& screen);

template <pos W, pos H> class Screen {
    friend ostream& operator<<<W, H>(ostream& os, const Screen<W, H>& screen);
    friend istream& operator>><W, H>(istream& is, const Screen<W, H>& screen);

    pos cursor = 0;
    string content;

   public:
    Screen() : content(W * H, ' ') {}
    Screen(char c) : content(W * H, c) {}

    char get() const { return content[cursor]; }
    char get(pos r, pos c) const { return content[r * W + c]; }

    void set_content(const string& s) { content = s; }
};

template <pos W, pos H>
ostream& operator<<(ostream& os, const Screen<W, H>& screen) {
    os << screen.content;
    return os;
}

template <pos W, pos H> istream& operator>>(istream& is, Screen<W, H>& screen) {
    string s;
    is >> s;
    screen.set_content(s);
    return is;
}
