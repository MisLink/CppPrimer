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
    cout << v[0] << endl;
    cout << "only one" << endl;
  } else {
    for (decltype(v.size()) i = 0; i != v.size() - 1; i++) {
      cout << v[i] + v[i + 1] << endl;
    }
  }
  cout << endl;
  decltype(v.size()) size = v.size();
  if (size % 2 != 0) {
    size = size / 2 + 1;
  } else {
    size = size / 2;
  }
  for (decltype(v.size()) i = 0; i != size; i++) {
    cout << v[i] + v[v.size() - i - 1] << endl;
  }
  return 0;
}
