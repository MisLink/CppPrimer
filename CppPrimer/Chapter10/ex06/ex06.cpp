#include <algorithm>
using std::fill_n;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  fill_n(vec.begin(), vec.size(), 0);
  for (auto& x : vec) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
