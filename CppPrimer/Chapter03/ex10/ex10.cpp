#include <cctype>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
int main() {
  string str;
  cin >> str;
  for (auto x : str) {
    if (!ispunct(x)) {
      cout << x;
    }
  }
  cout << endl;
  return 0;
}
