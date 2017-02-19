#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int main() {
  int arr[10];
  int *b = begin(arr);
  int *e = end(arr);
  for (auto i = b; i != e; i++) {
    *i = 0;
  }
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}
