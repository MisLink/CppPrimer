#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main(int argc, char* argv[]) {
  string str;
  for (int i = 1; i != argc; i++) {
    str += argv[i];
    str += " ";
  }
  cout << str << endl;
  return 0;
}
