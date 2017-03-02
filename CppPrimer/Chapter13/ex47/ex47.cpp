#include "ex47.h"
int main() {
  char a[] = "abcd";
  String s(a);
  String s2 = s;
  s2 = s;
  return 0;
}
