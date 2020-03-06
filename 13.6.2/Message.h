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
 * 错误反思:
 * 1. 想通过指针调用方法的时候不用  (*p).f(), 直接写成p->f() 就可以
 * 2. 拷贝赋值运算符定义的时候, 记得返回*this
 **/

class Message;
class Folder {
    set<Message *> msgs;

    void link_msgs();

    void unlink_msgs();

   public:
    Folder() = default;
    Folder(Folder &ori);
    Folder &operator=(Folder &cp);
    ~Folder();

    void add_msg(Message *msg) {
        msgs.insert(msg);
    }

    void rem_msg(Message *msg) {
        msgs.erase(msg);
    }

    void print_msgs();
};

class Message {
    string msg;
    set<Folder *> folders;

    void unlink_folders() {
        for (auto &folder : folders) {
            folder->rem_msg(this);
        }
    }

    void link_folders() {
        for (auto &folder : folders) {
            folder->add_msg(this);
        }
    }

    void relink_folders(Message *m) {
        folders = std::move(m->folders);
        for (auto &folder : folders) {
            folder->rem_msg(m);
            folder->add_msg(this);
        }
        m->folders.clear();  //确保销毁m是无害的
    }

   public:
    explicit Message(const string &s) : msg(s) {}
    Message(Message &ori) : msg(ori.msg), folders(ori.folders) {
        link_folders();
    }

    Message(Message &&ori) : msg(std::move(ori.msg)) {
        relink_folders(&ori);
    }

    Message &operator=(Message &cp) {
        unlink_folders();
        msg = cp.msg;
        folders = cp.folders;
        link_folders();
        return *this;
    }

    Message &operator=(Message &&cp) {
        if (&cp != this) {
            unlink_folders();
            msg = std::move(cp.msg);
            relink_folders(&cp);
        }
        return *this;
    }

    ~Message() {
        unlink_folders();
    }

    void swap(Message &a, Message &b) {
        for (auto &folder : a.folders) {
            folder->rem_msg(&a);
        }
        for (auto &folder : b.folders) {
            folder->rem_msg(&b);
        }

        std::swap(a.msg, b.msg);
        std::swap(a.folders, b.folders);

        for (auto &folder : a.folders) {
            folder->add_msg(&a);
        }
        for (auto &folder : b.folders) {
            folder->add_msg(&b);
        }
    }

    void save(Folder &folder) {
        folders.insert(&folder);
        folder.add_msg(this);
    }

    void remove(Folder &folder) {
        folders.erase(&folder);
        folder.rem_msg(this);
    }

    void add_folder(Folder *folder) {
        folders.insert(folder);
    }

    void rem_folder(Folder *folder) {
        folders.erase(folder);
    }

    string &get() {
        return msg;
    }
};

void Folder::link_msgs() {
    for (auto &msg : msgs) {
        msg->save(*this);
    }
}

void Folder::unlink_msgs() {
    for (auto &msg : msgs) {
        msg->remove(*this);
    }
}

Folder::Folder(Folder &ori) {
    msgs = ori.msgs;
    link_msgs();
}

Folder &Folder::operator=(Folder &cp) {
    unlink_msgs();
    msgs = cp.msgs;
    link_msgs();
}

Folder::~Folder() {
    unlink_msgs();
}

void Folder::print_msgs() {
    for (auto &msg : msgs) {
        cout << (msg->get()) << endl;
    }
}

int main(int argc, char **argv) {
    Message a("a");
    Message b("b");
    Message c("c");

    Folder f;
    a.save(f);
    b.save(f);

    f.print_msgs();
}