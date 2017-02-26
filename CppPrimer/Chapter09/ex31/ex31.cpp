#include <forward_list>
#include <iostream>
#include <list>
using std::forward_list;
using std::cout;
using std::endl;
using std::list;
void list_test() {
  list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = li.begin();
  while (iter != li.end()) {
    if (*iter % 2) {
      iter = li.insert(iter, *iter);
      iter++;
      iter++;
    } else {
      iter = li.erase(iter);
    }
  }
  for (auto& x : li) {
    cout << x << ' ';
  }
  cout << endl;
}
void forward_list_test() {
  forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = fli.begin();
  auto prev = fli.before_begin();
  while (iter != fli.end()) {
    if (*iter % 2) {
      iter = fli.insert_after(prev, *iter);
      iter++;
      iter++;
      prev++;
      prev++;
    } else {
      iter = fli.erase_after(prev);
    }
  }
  for (auto& x : fli) {
    cout << x << ' ';
  }
  cout << endl;
}
int main() {
  list_test();
  forward_list_test();
}
