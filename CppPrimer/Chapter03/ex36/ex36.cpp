#include <iostream>
#include <vector>
using std::begin;
using std::end;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
int main() {
  int arr[5];
  int arr_[5];
  for (auto &x : arr) {
    cin >> x;
  }
  for (auto &x : arr_) {
    cin >> x;
  }
  bool flag = true;
  for (auto i = begin(arr), ii = begin(arr_); i != end(arr), ii != end(arr_);
       i++, ii++) {
    if (*i != *ii) {
      flag = false;
    }
  }
  if (flag == false) {
    cout << "not equal\n";
  } else {
    cout << "equal\n";
  }
  vector<int> v(5);
  vector<int> v_(5);
  for (auto &x : v) {
    cin >> x;
  }
  for (auto &x : v_) {
    cin >> x;
  }
  if (v != v_) {
    cout << "not equal\n";
  } else {
    cout << "equal\n";
  }
  return 0;
}
