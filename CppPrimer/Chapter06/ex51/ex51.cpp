#include <iostream>
using std::cout;
using std::endl;
void f() { cout << "null" << endl; }
void f(int i) { cout << i << endl; }
void f(int i, int i_) { cout << i << " " << i_ << endl; }
void f(double i, double i_ = 3.14) { cout << i << " " << i_ << endl; }
int main() {
  //f(2.56, 42);
  f();
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  return 0;
}
