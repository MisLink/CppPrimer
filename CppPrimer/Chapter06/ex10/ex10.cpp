#include <iostream>
void swap(int* _a, int* _b);
int main() {
  int a, b;
  std::cin >> a >> b;
  swap(&a, &b);
  std::cout << a << ' ' << b << std::endl;
  return 0;
}
void swap(int* _a, int* _b) {
  int temp;
  temp = *_a;
  *_a = *_b;
  *_b = temp;
}
