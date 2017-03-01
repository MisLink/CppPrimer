#include <iostream>
#include <memory>
#include <string>
int main() {
  std::allocator<std::string> alloc;
  auto const p = alloc.allocate(5);
  std::string str;
  auto q = p;
  while (std::cin >> str) {
    alloc.construct(q++, str);
  }
  auto t = p;
  while (t != q) {
    std::cout << *t << std::endl;
    t++;
  }
  alloc.deallocate(p, 5);
  return 0;
}
