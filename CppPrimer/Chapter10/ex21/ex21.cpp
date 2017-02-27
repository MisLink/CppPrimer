#include <iostream>
using std::cout;
using std::endl;
int main() {
  int i = 7;
  auto lambda = [&i]() -> bool {
    i--;
    if (i > 0) {
      return false;
    } else {
      return true;
    }
  };
  while (!lambda()) {
    cout << i << endl;
  }
  return 0;
}
