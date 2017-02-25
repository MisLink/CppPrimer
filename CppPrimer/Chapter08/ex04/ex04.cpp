#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::ifstream;
void function(string file, vector<string>& vec) {
  ifstream open(file);
  string str;
  while (std::getline(open, str)) {
    vec.push_back(str);
  }
  open.close();
}

int main() {
  vector<string> vec;
  function(
      "D:\\document\\C++Projects\\CppPrimer\\CppPrimer\\Chapter08\\ex04\\add_"
      "item",
      vec);
  for (auto x : vec) {
    std::cout << x << std::endl;
  }
  return 0;
}
