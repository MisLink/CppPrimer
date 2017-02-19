#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
int main() {
  vector<int> v(11, 0);
  unsigned grade;
  while (cin >> grade) {
    if (grade <= 100) {
      (*(v.begin() + grade / 10))++;
    }
  }
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
