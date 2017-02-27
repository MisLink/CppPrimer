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
