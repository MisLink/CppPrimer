#include <iostream>

int main() {
  int a = 5;
  auto f = [a](const int& b) { return a + b; };
  std::cout << f(6) << std::endl;
}
