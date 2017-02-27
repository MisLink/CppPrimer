#include <algorithm>
using std::count;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  vector<int> vec;
  int x;
  while (cin >> x) {
    vec.push_back(x);
  }
  cout << count(vec.begin(), vec.end(), 5) << endl;
  return 0;
}
