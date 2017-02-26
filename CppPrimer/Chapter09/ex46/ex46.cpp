#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

string function(string s, string pre, string back) {
  s.insert(0, pre);
  s.insert(s.size(), back);
  return s;
}
int main() {
  string name("alan");
  cout << function(name, "Mr.", ",Jr.") << endl;

  return 0;
}
