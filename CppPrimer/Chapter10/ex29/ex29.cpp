#include <iterator>
using std::istream_iterator;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
#include <iostream>
int main() {
  ifstream in(
      "D:/document/C++Projects/CppPrimer/CppPrimer/Chapter10/ex29/outFile1");
  istream_iterator<string> input(in);
  istream_iterator<string> eof;
  vector<string> vec(input, eof);
  for (auto& x : vec) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
  return 0;
}
