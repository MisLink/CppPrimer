#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::string;
int main() {
  list<char *> l{"hello", "world", "!"};
  vector<string> vec;
  vec.assign(l.begin(), l.end());
  for (auto &x : vec) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
