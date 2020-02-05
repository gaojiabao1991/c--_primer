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

//因为Window_mgr和Screen互相引用, 先定义任何一个都会找不到另一个;
//这里需要提前声明但不定义Screen
class Screen;

class Window_mgr {
   public:
    using ScreenIdx = vector<Screen>::size_type;
    Window_mgr() = default;
    Window_mgr(Screen& s) { screens.push_back(s); }

    void clear(ScreenIdx idx);
    Screen& get(ScreenIdx idx) {
        return screens[idx];
    }

   private:
    //这里原本默认初始化一个元素的列表, 但是因为现在使用的是声明而未定义的Screen, 不能这么写了
    vector<Screen> screens;  //{Screen(64, 48, ' ')};
};

class Screen {
   public:
    friend void Window_mgr::clear(ScreenIdx idx);

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

    void do_display(ostream& os) const {
        os << content << endl;
    }
};

void Window_mgr::clear(ScreenIdx idx) {
    Screen& s = screens[idx];
    s.content = string(s.wid * s.ht, ' ');
}
