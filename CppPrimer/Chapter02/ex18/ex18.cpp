#include <iostream>
int main() {
  int a = 1, b = 2;
  int *p = &a;
  std::cout << p << std::endl;
  std::cout << *p << std::endl;
  p = &b;
  std::cout << p << std::endl;
  std::cout << *p << std::endl;
  *p = a;
  std::cout << p << std::endl;
  std::cout << *p << std::endl;
  return 0;
}
