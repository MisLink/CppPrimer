#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;
int main() {
  vector<string> v;
  string str;
  while (cin >> str) {
    v.push_back(str);
  }
  for (auto x : v) {
    cout << x;
  }
  cout << endl;
  return 0;
}
