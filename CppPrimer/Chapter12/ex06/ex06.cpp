#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
vector<int>* function() {
  vector<int>* p = new vector<int>();
  return p;
}

void stdCin(vector<int>* vec) {
  int i;
  while (cin >> i) {
    vec->push_back(i);
  }
}

void print(vector<int>* vec) {
  for (auto& x : *vec) {
    cout << x << ' ';
  }
  cout << endl;
}

int main() {
  vector<int>* ptr = function();
  stdCin(ptr);
  print(ptr);
  delete ptr;
  return 0;
}
