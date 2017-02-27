#include <algorithm>
using std::count;
#include <string>
using std::string;
#include <list>
using std::list;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  list<string> lst;
  string x;
  while (cin >> x) {
    lst.push_back(x);
  }
  cout << count(lst.begin(), lst.end(), "a") << endl;
  return 0;
}
