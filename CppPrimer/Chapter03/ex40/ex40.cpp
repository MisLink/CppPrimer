#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
int main() {
  char ch[] = "hello";
  char ch_[] = "world";
  char sum[11];
  strcpy_s(sum, ch);
  strcat_s(sum, ch_);
  cout << sum << endl;
  return 0;
}
