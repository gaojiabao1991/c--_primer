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
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

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
using std::forward_list;
using std::front_inserter;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

void process(const string& input, const string& output1, const string& output2) {
    ifstream inf(input);
    ofstream outf1(output1);
    ofstream outf2(output2);

    istream_iterator<int> in_it(inf), eof;
    ostream_iterator<int> out_inserter1(outf1, " ");
    ostream_iterator<int> out_inserter2(outf2, "\n");

    while (in_it != eof) {
        if (*in_it % 2 == 1) {
            out_inserter1 = *in_it;
        } else {
            out_inserter2 = *in_it;
        }
        in_it++;
    }
}

int main(int argc, char** argv) {
    process("input.txt", "output1.txt", "output2.txt");
}