#include <algorithm>
using std::find;
#include <list>
using std::list;
#include <iostream>
int main() {
  list<int> lst{0, 4, 0, 8, 6, 9, 0, 6, 98, 1};
  auto it = find(lst.rbegin(), lst.rend(), 0);
  std::cout << *it << std::endl;
  return 0;
}
