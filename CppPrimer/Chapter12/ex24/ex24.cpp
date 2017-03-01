#include <cstring>
#include <iostream>
#include <string>
using std::string;
int main() {
  string str;
  std::cin >> str;
  char* ch = new char[str.size() + 1];
  strcpy_s(ch, str.size() + 1, str.c_str());
  std::cout << ch << std::endl;
  delete[] ch;
  return 0;
}
