#include <algorithm>
#include <iostream>
#include <vector>

class Foo {
 public:
  Foo sorted() {
    std::sort(data.begin(), data.end());
    std::cout << "R value\n";
    return *this;
  }
  Foo sorted() const {
    std::cout << "L value\n";
    return Foo(*this).sorted();
  }

 private:
  std::vector<int> data;
};

int main() {
  Foo foo;
  foo.sorted();
  return 0;
}
