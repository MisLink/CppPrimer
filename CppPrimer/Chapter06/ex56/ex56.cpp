#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
int mul(int n1, int n2) { return n1 * n2; }
int div_(int n1, int n2) { return n1 / n2; }
int f(int, int);
using pf = int (*)(int, int);
using pf = decltype(f)*;
using pf = int (*)(int, int);
typedef decltype(f)* pf;
typedef int (*pf)(int, int);

int main() {
  vector<pf> v{add, sub, mul, div_};
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << (*i)(4, 2) << endl;
  }
  return 0;
}
