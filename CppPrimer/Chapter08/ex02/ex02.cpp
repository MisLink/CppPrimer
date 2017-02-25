#include <iostream>
#include <string>
using std::string;
using std::istream;

istream& function(istream& is) {
  string str;
  while (is >> str) {
    std::cout << str << std::endl;
  }
  is.clear();
  return is;
}

int main() {
  istream& is = function(std::cin);
  std::cout << is.rdstate() << std::endl;
  return 0;
}
