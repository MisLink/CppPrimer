#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> v(begin(arr), end(arr));
  for (auto &x : v) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
