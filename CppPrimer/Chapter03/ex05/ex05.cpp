#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
  string str1;
  string sum1;
  while (cin >> str1) {
    sum1 += str1;
  }
  cout << sum1 << endl;
  cin.clear();
  string str2;
  string sum2;
  while (cin >> str2) {
    sum2 = sum2 + str2 + ' ';
  }
  cout << sum2 << endl;
  return 0;
}
