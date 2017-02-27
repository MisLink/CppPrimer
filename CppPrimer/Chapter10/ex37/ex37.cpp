#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::copy;
#include <iterator>
using std::back_inserter;
int main() {
  vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> lst;
  copy(vec.rbegin() + 2, vec.rbegin() + 7, back_inserter(lst));
  for (auto& x : lst) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
