#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
int main() {
  vector<int> v;
  int num;
  while (cin >> num) {
    v.push_back(num);
  }
  for (auto x : v) {
    cout << x;
  }
  cout << endl;
  return 0;
}
