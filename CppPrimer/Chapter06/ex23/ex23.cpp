#include <iostream>
void print(int a) { std::cout << a; }
void print(int (&a)[2]) {
  for (int i : a) {
    std::cout << i << ' ';
  }
}
int main() {
  int i = 0;
  int j[2] = {0, 1};
  print(i);
  std::cout << std::endl;
  print(j);
  std::cout << std::endl;
  return 0;
}
