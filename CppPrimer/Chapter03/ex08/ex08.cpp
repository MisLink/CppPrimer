#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
int main() {
  string str1;
  cin >> str1;
  for (decltype(str1.size()) i = 0; i < str1.size(); i++) {
    str1[i] = 'X';
  }
  cout << str1 << endl;
  string str2;
  cin >> str2;
  decltype(str2.size()) i = 0;
  while (i < str2.size()) {
    str2[i] = 'X';
    i++;
  }
  cout << str2 << endl;
  return 0;
}
