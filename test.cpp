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
#include <numeric>
#include <set>
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
using std::find;
using std::forward_list;
using std::front_inserter;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istream_iterator;
using std::istringstream;
using std::list;
using std::map;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::set;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::vector;
using namespace std::placeholders;

int main(int argc, char** argv) {
    const char* str1 = "abc";
    const char* str2 = "def";

    char* s3 = new char[strlen(str1) + strlen(str2) + 1];
    strcat(s3, str1);
    strcat(s3, str2);

    cout << (strlen(s3)) <<endl;

    
}