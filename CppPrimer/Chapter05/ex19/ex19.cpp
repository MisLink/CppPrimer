#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string str1, str2;
  cout << "please input two strings: \n";
  cin >> str1 >> str2;
  do {
    if (str1.size() < str2.size()) {
      cout << str1 << endl;
    } else {
      cout << str2 << endl;
    }
    cout << "please input two strings: \n";
  } while (cin >> str1 >> str2);
  return 0;
}
