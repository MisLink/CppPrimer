#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  for (auto x : arr) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
