#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::list;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vec(std::begin(ia), std::end(ia));
  for (auto iter = vec.begin(); iter != vec.end();) {
    if (!((*iter) % 2)) {
      iter = vec.erase(iter);
    } else {
      iter++;
    }
  }
  list<int> l(std::begin(ia), std::end(ia));
  for (auto iter = l.begin(); iter != l.end();) {
    if ((*iter) % 2) {
      iter = l.erase(iter);
    } else {
      iter++;
    }
  }
  for (auto& x : vec) {
    cout << x << ' ';
  }
  cout << endl;
  for (auto& x : l) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
