#include <iostream>
#include <sstream>
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
  std::istringstream iss("The quick brown fox jumps over the lazy dog");
  function(iss);
  return 0;
}
