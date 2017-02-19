#include <cstring>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main() {
  string str("hello");
  string str_("world");
  if (str == str_) {
    cout << "euqal\n";
  } else {
    cout << "not equal\n";
  }
  char ch[] = "hello";
  char ch_[] = "world";
  if (strcmp(ch, ch_)) {
    cout << "not equal\n";
  } else {
    cout << "equal\n";
  }
  return 0;
}
