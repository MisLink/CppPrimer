#include <iostream>
int larger(const int a, const int* b);
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << larger(a, &b) << std::endl;
  return 0;
}
int larger(const int a, const int* b) {
  if (a > *b) {
    return a;
  } else {
    return *b;
  }
}
