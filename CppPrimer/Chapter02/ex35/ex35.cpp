#include <iostream>
int main() {
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const auto j2 = i, &k2 = i;
  printf("%d %d %d %d %d %d", i, j, k, *p, j2, k2);
  return 0;
}
