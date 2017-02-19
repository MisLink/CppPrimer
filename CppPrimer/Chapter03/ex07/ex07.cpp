#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
int main() {
  string str;
  cin >> str;
  for (char &x : str) {
    x = 'X';
  }
  cout << str << endl;
  return 0;
}
