#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string str1, str2;
  cin >> str1 >> str2;
  if (str1 > str2) {
    cout << str1 << endl;
  } else if (str1 < str2) {
    cout << str2 << endl;
  } else {
    cout << "equal" << endl;
  }
  cin >> str1 >> str2;
  if (str1.size() > str2.size()) {
    cout << str1 << endl;
  } else if (str1.size() < str2.size()) {
    cout << str2 << endl;
  } else {
    cout << "equal" << endl;
  }
  return 0;
}
