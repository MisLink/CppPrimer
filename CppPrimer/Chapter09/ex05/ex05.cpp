#include <iostream>
#include <vector>
using std::vector;

auto find_value(vector<int>::const_iterator begin,
                vector<int>::const_iterator end, const int value) {
  for (auto& i = begin; i != end; i++) {
    if (*i == value) {
      return i;
    }
  }
  return end;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6};
  auto x = find_value(v.begin(), v.end(), 5);
  if (x != v.end()) {
    std::cout << *x << std::endl;
  }
}
