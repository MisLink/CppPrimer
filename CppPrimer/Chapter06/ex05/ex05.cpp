#include <iostream>
double Abs(double i) { return i >= 0 ? i : -i; }
int main() {
  double i;
  std::cin >> i;
  std::cout << Abs(i) << std::endl;
  return 0;
}
