#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
  vector<int> vec1{0, 1, 2, 3, 4, 5};
  vector<int> vec2{1, 2, 3, 4, 5};
  if (vec1 == vec2) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
