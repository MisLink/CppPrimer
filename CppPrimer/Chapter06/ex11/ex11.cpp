#include <iostream>
void reset(int &i);
int main() {
  int i = 42;
  std::cout << "before reset: ";
  std::cout << i << std::endl;
  reset(i);
  std::cout << "after reset: ";
  std::cout << i << std::endl;
  return 0;
}
void reset(int &i) { i = 0; }
