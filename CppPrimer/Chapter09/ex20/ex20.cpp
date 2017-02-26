#include <deque>
#include <iostream>
#include <list>
using std::list;
using std::deque;
using std::cout;
using std::endl;

int main() {
  list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> odd, even;
  for (auto iter = l.begin(); iter != l.end(); ++iter) {
    if ((*iter) % 2) {
      odd.push_back(*iter);
    } else {
      even.push_back(*iter);
    }
  }
  for (auto& x : odd) {
    cout << x << ' ';
  }
  cout << endl;
  for (auto& x : even) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
