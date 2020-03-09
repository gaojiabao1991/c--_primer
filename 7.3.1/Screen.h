#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::initializer_list;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Screen {
   public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos wid, pos ht) : wid(wid), ht(ht), content(wid * ht, ' ') {}
    Screen(pos wid, pos ht, char c) : wid(wid), ht(ht), content(wid * ht, c) {}

    char get() const { return content[cursor]; }
    char get(pos r, pos c) const { return content[r * wid + c]; }

    Screen& set(char c) {
        content[cursor] = c;
        return *this;
    }

    Screen& set(pos r, pos c, char ch) {
        content[r * wid + c] = ch;
        return *this;
    }

    Screen& move(pos r, pos c) {
        cursor = r * wid + c;
        return *this;
    }

    Screen& display(ostream& os) {
        // do_display(os);
        this->do_display(os);
        return *this;
    }

    const Screen& display(ostream& os) const {
        // do_display(os);
        this->do_display(os);
        return *this;
    }

   private:
    pos cursor = 0;
    pos wid = 0;
    pos ht = 0;
    string content;

    void do_display(ostream& os) const { os << content; }
};