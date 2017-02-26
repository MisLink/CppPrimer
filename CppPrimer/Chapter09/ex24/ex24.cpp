#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main() {
  vector<int> vec;
  // Fault
  try {
    cout << vec.at(0) << endl;
  } catch (const std::exception&) {
    cout << "at error!" << endl;
  }

  // cout << vec[0] << endl;
  // cout << vec.front() << endl;
  // cout << *vec.begin() << endl;
  return 0;
}
