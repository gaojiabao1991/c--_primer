#include <array>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::end;
using std::endl;
using std::ends;
using std::forward_list;
using std::ifstream;
using std::initializer_list;
using std::istream;
using std::istringstream;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::string;
using std::vector;

int main(int argc, char **argv) {
    //推测题目代码的意图是, 在前半个vector的元素里, 找到所有值==some_val的值, 每找到一个, 就在这个值前面插入一个2*some_val的值
    //需要注意的是, 每次对vector执行insert操作后, 都会导致相关的迭代器, 引用和指针失效, 因此题目的源代码是错误的

    int some_val = 3;
    //测试数据的前一半元素是3, 2, 3, 4, 5
    //some_val=3, 因此, 正确的处理结果是iv变成12个元素, 分别在两个元素3的前面插入两个元素6, 即:
    //{6, 3, 2, 6, 3, 4, 5, 6, 7, 8, 9, 10}

    vector<int> iv = {3, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    vector<int>::iterator iter = iv.begin();
    int left = iv.size() / 2;  //总共要检查的元素数量, 初始是数组一般, 每处理一个减一

    // while (iter != mid) {
    //     if (*iter == some_val)
    //         iv.insert(iter, 2 * some_val);
    //     iter++;
    // }

    while (left != 0) {
        if (*iter == some_val) {
            //通过给iter重新赋值避免失效
            //insert返回指针指向新插入的元素, +1后指向原来那个元素
            iter = iv.insert(iter, 2 * some_val) + 1;
        }
        iter++;
        left--;
    }

    cout << (iv.size()) << endl;
    for (auto &i : iv) {
        cout << (i) << " ";
    }
    cout << endl;
}