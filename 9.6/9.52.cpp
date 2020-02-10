#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;
int main() {
    // 原题我的理解是用stack来计算含括号的表达式.
    // 标准方法是先转成后缀表达式, 再计算, 中缀转后缀算法有点复杂, 这里不写了, 直接用stack计算现成的后缀表达式
    // 中缀表达式: 3*(1+2)+1)/(4-2)+3, 结果=8
    // 转化为后缀表达式: 312+*1+42-/3+
    string s = "312+*1+42-/3+";  

    stack<int> stack;
    for (auto &c : s) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (c == '+') {
                stack.push(a + b);
            } else if (c == '-') {
                stack.push(a - b);
            } else if (c == '*') {
                stack.push(a * b);
            } else if (c == '/') {
                stack.push(a / b);
            }
        }
    }

    cout << (stack.top()) << endl;
}