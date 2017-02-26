#include <fstream>
#include <iostream>
#include <string>
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

int main() {
  string filename;
  std::cin >> filename;
  ifstream input(filename);
  string longest_word;
  string word;
  while (input >> word) {
    if (word.find_first_not_of("acemnorsuvwxz") == string::npos &&
        word.size() > longest_word.size()) {
      longest_word = word;
    }
  }
  cout << longest_word << endl;
  return 0;
}
