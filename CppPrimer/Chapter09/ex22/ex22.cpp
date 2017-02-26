#include <iostream>
#include <vector>
using std::vector;

int main() {
  /*vector<int> v{1, 9, 1, 9, 9, 9, 1, 1};
  auto iter = v.begin();
  auto mid = v.begin() + v.size() / 2;
  while (iter != mid) {
    if (*iter == 1) {
      v.insert(iter, 2 * 1);
    }
  }*/
  vector<int> v{1, 9, 1, 9, 9, 9, 1, 1};
  auto iter = v.begin();
  auto mid = [&] { return v.begin() + v.size() / 2; };
  while (iter != mid()) {
    if (*iter == 1) {
      iter = v.insert(iter, 2 * 1);
      iter++;
    }
    iter++;
  }
  for (auto& x : v) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
}
