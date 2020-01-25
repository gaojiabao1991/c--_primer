#include <iostream>

int main() {
  int i = 0, &r = i;
  auto a = r;  // a 是int

  const int ci = i, &cr = ci;  // ci 是 const int; cr是常量引用
  auto b = ci;                 // b是int
  auto c = cr;                 // c是int
  auto d = &i;                 // d是int 指针
  auto e = &ci;                // e是指向int常量的指针

  const auto f = ci;  // f是const int

  auto &g = ci;  // g是常量引用
  // auto &h = 42; //非常量引用不能指向字面值
  const auto &j = 42;  // j是常量引用

  auto k = ci, &l = i;     // k是Int, l是int引用
  auto &m = ci, *p = &ci;  // m是int常量引用, p是指向常量int的指针

  //auto &n = i, *p2=&ci; //错误, 对&n来说, auto=int, 对*p2来说, auto=const int

  a=42;
  b=42;
  c=42;
  //d=42;
  //e=42;
  // g=42;
}