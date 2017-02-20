#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  char ch;
  while (cin >> ch) {
    if (ch == 'a') {
      aCnt++;
    } else if (ch == 'e') {
      eCnt++;
    } else if (ch == 'i') {
      iCnt++;
    } else if (ch == 'o') {
      oCnt++;
    } else if (ch == 'u') {
      uCnt++;
    }
  }
  cout << "Number of vowel a: " << aCnt << endl
       << "Number of vowel e: " << eCnt << endl
       << "Number of vowel i: " << iCnt << endl
       << "Number of vowel o: " << oCnt << endl
       << "Number of vowel u: " << uCnt << endl;
  return 0;
}
