#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class HasPtr {
  friend void swap(HasPtr& lhs, HasPtr& rhs);

 public:
  HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& hp) : ps(new std::string(*(hp.ps))), i(hp.i) {}
  HasPtr& operator=(HasPtr hp) {
    swap(*this, hp);
    return *this;
  }
  bool operator<(const HasPtr& rhs) {
    std::cout << "<" << std::endl;
    return *(this->ps) < *rhs.ps;
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
  HasPtr p1("aa"), p2("bb"), p3("cc");
  std::vector<HasPtr> vec{p1, p2, p3};
  std::sort(vec.begin(), vec.end());
  return 0;
}
