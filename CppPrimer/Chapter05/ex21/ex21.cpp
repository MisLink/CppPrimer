#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string str, temp;
  while (cin >> str) {
    if (str != temp || !isupper(str[0])) {
      temp = str;
      continue;
    } else {
      break;
    }
  }
  if (cin.eof()) {
    cout << "no word was repeated." << endl;
  } else {
    cout << str << " was repeated." << endl;
  }
  return 0;
}
