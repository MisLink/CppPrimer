#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  int arr_[10];
  for (int i = 0; i < 10; i++) {
    arr_[i] = arr[i];
  }
  for (auto x : arr_) {
    cout << x << ' ';
  }
  cout << endl;
  vector<int> v(10);
  for (auto i = v.begin(); i != v.end(); i++) {
    *i = i - v.begin();
  }
  vector<int> v_(v);
  for (auto x : v_) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
