#include <iostream>
int main() {
  std::cout << "How many numbers will you enter?" << std::endl;
  int limit = 0;
  std::cin >> limit;
  int v = 0, sum = 0;
  while (limit != 0 && std::cin >> v) {
    limit--;
    sum += v;
  }
  std::cout << sum << std::endl;
  return 0;
}
