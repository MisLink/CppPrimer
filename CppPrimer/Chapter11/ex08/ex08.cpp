#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
int main() {
  vector<string> vec{"a", "the", "an"};
  string word;
  while (cin >> word) {
    for (auto& x : vec) {
      if (word == x) {
        cout << "excluded!\n";
      }
    }
  }
  return 0;
}
