#include <vector>
using std::vector;
#include <iterator>
using std::back_inserter;
using std::front_inserter;
using std::inserter;
#include <list>
using std::list;
#include <algorithm>
using std::copy;
#include <iostream>
using std::cout;
using std::endl;
int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> vec1, vec2;
  list<int> lst;
  auto it1 = back_inserter(vec1);
  auto it2 = front_inserter(lst);
  auto it3 = inserter(vec2, vec2.begin());
  copy(vec.begin(), vec.end(), it1);
  for (auto& x : vec1) {
    cout << x << ' ';
  }
  cout << endl;
  copy(vec.begin(), vec.end(), it2);
  for (auto& x : lst) {
    cout << x << ' ';
  }
  cout << endl;
  copy(vec.begin(), vec.end(), it3);
  for (auto& x : vec2) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
