#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
int main() {
  vector<string> vec{"a", "ab", "abc"};
  for (auto i = vec.end(); i != vec.begin();) {
    --i;
    cout << *i << ' ';
  }
  cout << endl;
  return 0;
}
