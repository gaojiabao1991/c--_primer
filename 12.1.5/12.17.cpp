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
using std::make_shared;
using std::map;
using std::multimap;
using std::multiset;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::ostringstream;
using std::pair;
using std::set;
using std::shared_ptr;
using std::sort;
using std::stable_sort;
using std::string;
using std::unique;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using namespace std::placeholders;

int main(int argc, char **argv) {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    // IntP p0(ix); //ERROR
    // IntP p1(pi); //runtime error, 退出时会对pi指向对象执行delete, 但是pi指向的对象不是new 创建的

    // IntP p2(pi2); //正确, 但是可能会造成pi2成为空悬指针

    // IntP p3(&ix); //runtime error, 退出时会对ix对象执行delete, 但ix不是new创建的

    // IntP p4(new int(2048)); //right

    /**
     * logic wrong, 第一个独占指针out of scope后, 会把内存释放, 
     * 此时可能有其他程序会使用释放的内存, 而第二个指针out of scope后, 会再释放一次, 可能会产生严重错误
     * */
    IntP p2(pi2);
    IntP p5(p2.get());

    cout << (*p2) << endl;
    cout << (*p5) << endl;
}