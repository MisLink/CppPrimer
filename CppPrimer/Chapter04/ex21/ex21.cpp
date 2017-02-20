#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto &x : v) {
    (x % 2 == 0) ? (x = x) : (x = x * 2);
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
