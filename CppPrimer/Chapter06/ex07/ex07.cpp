#include <iostream>
int count() {
  static int cnt = 0;
  return cnt++;
}
int main() {
  for (int i = 0; i < 5; i++) {
    std::cout << count() << std::endl;
  }
  return 0;
}
