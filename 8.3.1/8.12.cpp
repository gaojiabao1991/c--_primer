#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::ends;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char **argv) {
    string line, word;
    vector<PersonInfo> persons;

    istringstream record;
    while (getline(cin, line)) {
        PersonInfo p;
        // istringstream record(line);
        record.clear();  //这里必须要clear流状态
        record.str(line);

        record >> p.name;
        while (record >> word) {
            p.phones.push_back(word);
        }
        persons.push_back(p);
    }

    for (auto &p : persons) {
        cout << (p.name) << " ";
        for (auto &phone : p.phones) {
            cout << (phone) << " ";
        }
        cout << ("\n");
    }
}
