#include <iostream>
void swap(int *&a, int *&b);
int main() {
  int a;
  int b;
  int *p1 = &a;
  int *p2 = &b;
  std::cin >> a >> b;
  swap(p1, p2);
  std::cout << *p1 << ' ' << *p2 << std::endl;
  return 0;
}
void swap(int *&a, int *&b) {
  int *temp;
  temp = a;
  a = b;
  b = temp;
}
