#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
  vector<int> vec;
  for (vector<int>::size_type x = 0; x < 24; x++) {
    vec.push_back(x);
  }
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;
  while (vec.size() != vec.capacity()) {
    vec.push_back(42);
  }
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;
  vec.push_back(0);
  cout << "size: " << vec.size() << endl;
  cout << "capacity: " << vec.capacity() << endl;
  return 0;
}
