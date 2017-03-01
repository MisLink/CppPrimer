#include "ex20.h"
#include <iostream>
#include <string>
int main() {
  StrBlob blob;
  std::string str;
  while (getline(std::cin, str)) {
    blob.push_back(str);
  }
  for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend;
       pbeg.incr()) {
    std::cout << pbeg.deref() << std::endl;
  }
  return 0;
}
