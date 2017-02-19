#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main() {
  vector<int> v(10);
  for (auto &x : v) {
    cin >> x;
  }
  for (auto &x : v) {
    x *= 2;
  }
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
