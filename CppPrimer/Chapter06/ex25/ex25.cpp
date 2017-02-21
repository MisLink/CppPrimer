#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int main(int argc, char* argv[]) {
  string str;
  str = argv[1];
  str += argv[2];
  cout << str << endl;
  return 0;
}
