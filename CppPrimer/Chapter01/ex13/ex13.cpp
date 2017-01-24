#include <iostream>

void sum_50_to_100() {
  int sum = 50;
  for (int v = 50; v <= 100; v++) {
    sum += v;
  }
  std::cout << sum << std::endl;
}

void count_10_to_0() {
  for (int v = 10; v >= 0; v--) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
}

void count_v1_to_v2() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  if (v1 > v2) {
    for (int i = v1; i >= v2; i--) {
      std::cout << i << ' ';
    }
  } else {
    for (int i = v1; i <= v2; i++) {
      std::cout << i << ' ';
    }
  }
  std::cout << std::endl;
}

int main() {
  sum_50_to_100();
  count_10_to_0();
  count_v1_to_v2();
  return 0;
}
