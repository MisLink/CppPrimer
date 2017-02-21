#include <iostream>
int add(int i) {
  static int sum = 0;
  sum += i;
  return sum;
}
int main() {
  for (int i = 0; i < 5; i++) {
    std::cout << add(i) << std::endl;
  }
  return 0;
}
