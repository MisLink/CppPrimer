#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
bool judge(const string& s);
void lower(string& s);
int main() {
  string str{"HelloWorld"};
  if (judge(str)) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
  lower(str);
  cout << str << endl;
  return 0;
}
bool judge(const string& s) {
  for (auto c : s) {
    if (isupper(c)) {
      return true;
    }
  }
  return false;
}
void lower(string& s) {
  for (auto& c : s) {
    c = tolower(c);
  }
}
