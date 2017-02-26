#include <iostream>
#include <list>
#include <string>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  list<string> l;
  string str;
  while (cin >> str) {
    l.push_back(str);
  }
  for (auto iter = l.begin(); iter != l.end(); iter++) {
    cout << *iter << ' ';
  }
  cout << endl;
  return 0;
}
