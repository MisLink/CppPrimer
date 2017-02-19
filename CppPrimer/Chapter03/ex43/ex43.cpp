#include <iostream>
using std::cout;
using std::endl;
int main() {
  int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  for (const int(&p)[4] : ia) {
    for (int q : p) {
      cout << q << ' ';
    }
  }
  cout << endl;
  for (size_t i = 0; i != 3; i++) {
    for (size_t ii = 0; ii != 4; ii++) {
      cout << ia[i][ii] << ' ';
    }
  }
  cout << endl;
  for (int(*p)[4] = ia; p != ia + 3; p++) {
    for (int *q = *p; q != *p + 4; q++) {
      cout << *q << ' ';
    }
  }
  cout << endl;
  return 0;
}
