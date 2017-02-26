#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
using std::cout;
using std::endl;
int main() {
  list<int> l(5, 0);
  vector<double> vec(l.begin(), l.end());
  cout << "list: ";
  for (auto& x : l) {
    cout << x << ' ';
  }
  cout << endl;
  cout << "vector: ";
  for (auto& x : vec) {
    cout << x << ' ';
  }
  cout << endl;
  vector<int> veci(5, 1);
  vector<double> vec_(veci.begin(), veci.end());
  cout << "vector<int>: ";
  for (auto& x : veci) {
    cout << x << ' ';
  }
  cout << endl;
  cout << "vector<double>: ";
  for (auto& x : vec_) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
