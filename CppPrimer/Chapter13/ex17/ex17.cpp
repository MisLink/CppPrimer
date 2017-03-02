#include <iostream>
class Numbered {
 public:
  unsigned mysn;
  Numbered() {
    static unsigned i = 0;
    i++;
    mysn = i;
  }
  Numbered(const Numbered& n) {
    static unsigned i = 1;
    i++;
    mysn = i;
  }
};

void f(const Numbered& s) { std::cout << s.mysn << std::endl; }
int main() {
  Numbered a;
  Numbered b = a;
  Numbered c = b;
  f(a);
  f(b);
  f(c);
  return 0;
}
