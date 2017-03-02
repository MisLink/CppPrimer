#include "ex48.h"
#include <vector>
int main() {
  char a[] = "abcd";
  String s(a);
  std::vector<String> vec;
  for (int i = 0; i < 3; ++i) {
    vec.push_back(s);
  }
  return 0;
}
