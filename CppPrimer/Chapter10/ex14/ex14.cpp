#include <iostream>

int main() {
  auto f = [](const int& a, const int& b) { return a + b; };
  std::cout << f(2, 3) << std::endl;
}
