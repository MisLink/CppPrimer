#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
int main() {
  int a, b;
  cin >> a >> b;
  if (b == 0) {
    throw runtime_error("divisor is 0.\n");
  }
  cout << static_cast<double>(a) / b << endl;
  return 0;
}
