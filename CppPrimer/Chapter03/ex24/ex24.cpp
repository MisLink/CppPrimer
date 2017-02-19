#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;
int main() {
  vector<int> v;
  int num;
  while (cin >> num) {
    v.push_back(num);
  }
  if (v.empty()) {
    cout << "no data" << endl;
    return -1;
  } else if (v.size() == 1) {
    cout << *v.begin() << endl;
    cout << "only one" << endl;
  } else {
    for (auto i = v.begin(); i != v.end() - 1; i++) {
      cout << *i + *(i + 1) << endl;
    }
  }
  cout << endl;
  for (auto beg = v.begin(), end = v.end() - 1; beg <= end; ++beg, --end) {
    cout << *beg + *end << endl;
  }
  return 0;
}
