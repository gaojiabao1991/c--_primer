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

class Person {
    friend istream& read(istream& is, Person& p);
    friend ostream& print(ostream& os, const Person& p);

    string name = "";
    string addr = "";

   public:
    Person() = default;
    Person(const string& name, const string& addr) : name(name), addr(addr) {}

    string get_name() const { return name; }
    string get_addr() const { return addr; }
};

istream& read(istream& is, Person& p) {
    is >> p.name >> p.addr;
    return is;
}

ostream& print(ostream& os, const Person& p) {
    os << p.get_name() << " " << p.get_addr();
    return os;
}
