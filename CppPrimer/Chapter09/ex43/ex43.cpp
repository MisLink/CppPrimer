#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
void function(string &s, string oldVal, string newVal) {
  for (string::size_type i = 0; i != s.size(); i++) {
    if (s.substr(i, oldVal.size()) == oldVal) {
      s.erase(i, oldVal.size());
      s.insert(i, newVal);
    }
  }
}
int main() {
  string str{"To drive straight thru is a foolish, tho courageous act."};
  function(str, "tho", "though");
  function(str, "thru", "through");
  cout << str << endl;
  return 0;
}
