#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
  vector<int> v{0, 1, 2, 3, 4, 5};
  int arr[6];
  for (auto i = begin(arr); i != end(arr); i++) {
    *i = v[i - begin(arr)];
  }
  for (auto x : arr) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
