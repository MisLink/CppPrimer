#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;
int main() {
  list<int> l{1, 2, 3, 4, 5};
  vector<int> v{1, 2, 3, 4, 5};
  if (v == vector<int>(l.begin(), l.end())) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
