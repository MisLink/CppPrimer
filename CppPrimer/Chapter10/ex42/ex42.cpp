#include <list>
using std::list;
#include <algorithm>
using std::sort;
using std::unique;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
void elimDups(list<string>& words) {
  words.sort();
  words.unique();
}
int main() {
  list<string> lst{"the",  "quick", "red",  "fox", "jumps",
                   "over", "the",   "slow", "red", "turtle"};
  elimDups(lst);
  for (auto& x : lst) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
