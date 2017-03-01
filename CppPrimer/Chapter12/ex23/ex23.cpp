#include <cstring>
#include <iostream>
#include <string>
int main() {
  char* connect = new char[255]();
  strcat_s(connect, 255, "hello");
  strcat_s(connect, 255, "world");
  std::cout << connect << std::endl;
  delete[] connect;
  std::string str1 = "hello";
  std::string str2 = "world";
  std::cout << str1 + str2 << std::endl;
  return 0;
}
