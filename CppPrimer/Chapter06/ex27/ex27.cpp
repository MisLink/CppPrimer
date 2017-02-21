#include <initializer_list>
#include <iostream>
using std::cout;
using std::endl;
using std::initializer_list;
int add(initializer_list<int> li);
int main() {
  cout << add({1, 2, 3, 4, 5}) << endl;
  return 0;
}
int add(initializer_list<int> li) {
  int sum = 0;
  for (auto &elem : li) {
    sum += elem;
  }
  return sum;
}
