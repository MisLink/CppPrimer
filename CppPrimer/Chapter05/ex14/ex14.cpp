#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string val, val_;
  unsigned max = 0;
  string maxString;
  if (cin >> val) {
    unsigned cnt = 1;
    while (cin >> val_) {
      if (val == val_) {
        ++cnt;
      } else {
        if (cnt > max) {
          max = cnt;
          maxString = val;
        }
        val = val_;
        cnt = 1;
      }
    }
    cout << maxString << ": " << max << " times" << endl;
  }
  return 0;
}
