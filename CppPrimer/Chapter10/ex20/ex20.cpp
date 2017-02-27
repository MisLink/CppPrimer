#include <algorithm>
using std::count_if;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
auto longer_than_6(vector<string>& vec) -> unsigned {
  return count_if(vec.begin(), vec.end(),
                  [](string& s) { return s.size() >= 5; });
}
int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  cout << longer_than_6(vec) << endl;
  return 0;
}
