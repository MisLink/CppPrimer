#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main() {
  vector<int> v1, v2;
  int n;
  while (cin >> n) {
    v1.push_back(n);
  }
  cin.clear();
  while (cin >> n) {
    v2.push_back(n);
  }
  auto size = (v1.size() > v2.size()) ? v2.size() : v1.size();
  for (decltype(size) i = 0; i != size; ++i) {
    if (v1[i] != v2[i]) {
      cout << "false" << endl;
      break;
    }
    if (i == size - 1) {
      cout << "true" << endl;
    }
  }
  return 0;
}
