#include <iostream>
#include <string>
class HasPtr {
  friend void swap(HasPtr& lhs, HasPtr& rhs);

 public:
  HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp) : ps(new std::string(*(hp.ps))), i(hp.i) {}
  HasPtr& operator=(HasPtr hp) {
    swap(*this, hp);
    return *this;
  }
  ~HasPtr() { delete ps; }

 private:
  std::string* ps;
  int i;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "swap!" << std::endl;
}

int main() {
  HasPtr p1("aa"), p2("bb");
  p1 = p2;
  return 0;
}
