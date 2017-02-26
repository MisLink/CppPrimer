#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main() {
  vector<char> vec{'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
  string s(vec.begin(), vec.end());
  cout << s << endl;
  return 0;
}
