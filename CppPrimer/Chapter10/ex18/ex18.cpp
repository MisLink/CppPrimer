#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;
using std::for_each;
using std::partition;
#include <iostream>
using std::cout;
using std::endl;
void elimDups(vector<string>& vec) {
  sort(vec.begin(), vec.end());
  auto end_unique = unique(vec.begin(), vec.end());
  vec.erase(end_unique, vec.end());
}
void biggies(vector<string>& words, vector<string>::size_type sz) {
  elimDups(words);
  auto iter = partition(words.begin(), words.end(),
                        [sz](const string& s) { return sz > s.size(); });
  for_each(iter, words.end(), [](const string& s) { cout << s << ' '; });
  cout << endl;
}

int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  biggies(vec, 5);
  return 0;
}
