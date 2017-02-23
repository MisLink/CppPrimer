#include <vector>
using std::vector;
class NoDefault {
 public:
  NoDefault(int i) {}
};
class C {
 private:
  NoDefault ndf;

 public:
  C() : ndf(0) {}
};
int main() {
  // legal
  vector<C> vec(10);

  // illegal
  // vector<NoDefault> vec_(10);
  return 0;
}
