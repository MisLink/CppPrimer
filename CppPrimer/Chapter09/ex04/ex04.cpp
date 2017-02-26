#include <iostream>
#include <vector>
using std::vector;

bool find_value(vector<int>::const_iterator& begin,
                vector<int>::const_iterator& end, int value) {
  for (auto i = begin; i != end; i++) {
    if (*i == value) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  std::cout << find_value(v.begin(), v.end(), 10) << std::endl;
}
