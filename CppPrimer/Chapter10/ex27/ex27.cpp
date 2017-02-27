#include <algorithm>
using std::unique_copy;
#include <iterator>
using std::back_inserter;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::endl;
int main() {
  vector<int> vec{1, 2, 3, 3, 5, 6, 6, 8, 9, 0, 0};
  list<int> lst;
  unique_copy(vec.begin(), vec.end(), back_inserter(lst));
  for (auto& x : lst) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
