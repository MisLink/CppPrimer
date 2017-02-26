#include <forward_list>
#include <iostream>
using std::cout;
using std::endl;
using std::forward_list;

int main() {
  forward_list<int> fl{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto prev = fl.before_begin(), iter = fl.begin(); iter != fl.end();) {
    if ((*iter) % 2) {
      iter = fl.erase_after(prev);
    } else {
      prev = iter;
      ++iter;
    }
  }
  for (auto& x : fl) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
