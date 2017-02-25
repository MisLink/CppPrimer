#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

int main() {
  ifstream open(
      "D:\\document\\C++"
      "Projects\\CppPrimer\\CppPrimer\\Chapter08\\ex10\\sstream");
  vector<string> vec;
  string str;
  while (std::getline(open, str)) {
    vec.push_back(str);
  }
  for (auto& x : vec) {
    istringstream iss(x);
    string word;
    while (iss >> word) {
      std::cout << word << std::endl;
    }
  }
  return 0;
}
