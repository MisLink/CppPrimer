#include <iostream>
int fact() {
  int ret = 1;
  int val;
  std::cout << "Input a number: \n";
  std::cin >> val;
  while (val > 1) {
    ret *= val--;
  }
  return ret;
}
int main() {
  int j = fact();
  std::cout << j << std::endl;
  return 0;
}
