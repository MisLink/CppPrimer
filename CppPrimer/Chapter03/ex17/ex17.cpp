#include <cctype>
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
  for (auto &i : v) {
    for (auto &c : i) {
      c = toupper(c);
    }
  }
  for (auto i : v) {
    cout << i << endl;
  }
  return 0;
}
