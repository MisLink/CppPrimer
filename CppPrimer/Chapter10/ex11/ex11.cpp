#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <algorithm>
using std::sort;
using std::unique;
using std::stable_sort;
bool isShorter(const string& s1, const string& s2) {
  return s1.size() < s2.size();
}
ostream& print(vector<string> vec) {
  for (auto& x : vec) {
    cout << x << ' ';
  }
  return cout;
}
void elimDups(vector<string>& vec) {
  print(vec);
  cout << endl;
  sort(vec.begin(), vec.end());
  stable_sort(vec.begin(), vec.end(), isShorter);
  auto end_unique = unique(vec.begin(), vec.end());
  print(vec);
  cout << endl;
  vec.erase(end_unique, vec.end());
  print(vec);
  cout << endl;
}
int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  elimDups(vec);
  return 0;
}
