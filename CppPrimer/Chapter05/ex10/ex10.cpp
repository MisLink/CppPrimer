#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  char ch;
  while (cin >> ch) {
    switch (ch) {
      case 'a':
      case 'A':
        ++aCnt;
        break;
      case 'e':
      case 'E':
        ++eCnt;
        break;
      case 'i':
      case 'I':
        ++iCnt;
        break;
      case 'o':
      case 'O':
        ++oCnt;
        break;
      case 'u':
      case 'U':
        ++uCnt;
        break;
    }
  }
  cout << "Number of vowel a: " << aCnt << endl
       << "Number of vowel e: " << eCnt << endl
       << "Number of vowel i: " << iCnt << endl
       << "Number of vowel o: " << oCnt << endl
       << "Number of vowel u: " << uCnt << endl;
  return 0;
}
