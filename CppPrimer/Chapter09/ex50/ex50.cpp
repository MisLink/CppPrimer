#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
  vector<string> vec{"1", "2", "3", "4.5"};
  int sumi = 0;
  for (auto &x : vec) {
    sumi += std::stoi(x);
  }
  double sumd = 0.0;
  for (auto &x : vec) {
    sumd += std::stod(x);
  }
  cout << sumi << endl;
  cout << sumd << endl;
  return 0;
}
