#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
  vector<string> v;
  string str;
  while (getline(cin, str)) {
    if (!str.empty()) {
      v.push_back(str);
    }
  }
  auto first = v.begin();
  for (auto &c : *first) {
    c = toupper(c);
  }
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *i << endl;
  }
  return 0;
}
