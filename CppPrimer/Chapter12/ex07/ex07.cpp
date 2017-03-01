#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;
shared_ptr<vector<int>> function() {
  auto pv = std::make_shared<vector<int>>();
  return pv;
}

void stdCin(shared_ptr<vector<int>> pv) {
  int i;
  while (cin >> i) {
    pv->push_back(i);
  }
}

void print(shared_ptr<vector<int>> pv) {
  for (auto& x : *pv) {
    cout << x << ' ';
  }
  cout << endl;
}

int main() {
  shared_ptr<vector<int>> ptr = function();
  stdCin(ptr);
  print(ptr);
  return 0;
}
