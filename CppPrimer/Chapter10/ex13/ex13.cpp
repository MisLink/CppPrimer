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
using std::partition;
using std::stable_sort;
bool longer_than_5(const string& s) { return s.size() >= 5; }

void elimDups(vector<string>& vec) {
  auto middle = partition(vec.begin(), vec.end(), longer_than_5);
  for (auto i = vec.begin(); i != middle; ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}
int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  elimDups(vec);
  return 0;
}
