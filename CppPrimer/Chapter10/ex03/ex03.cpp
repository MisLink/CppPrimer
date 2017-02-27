#include <numeric>
using std::accumulate;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int sum = accumulate(vec.begin(), vec.end(), 0);
  cout << sum << endl;
  return 0;
}
