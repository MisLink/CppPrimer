#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;
using std::stable_sort;
using std::find_if;
using std::for_each;
#include <iostream>
using std::cout;
using std::endl;
void elimDups(vector<string> &vec) {
  sort(vec.begin(), vec.end());
  auto end_unique = unique(vec.begin(), vec.end());
  vec.erase(end_unique, vec.end());
}
void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words);
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });
  auto iter = find_if(words.begin(), words.end(),
                      [sz](const string &s) { return s.size() >= sz; });
  for_each(iter, words.end(), [](const string &s) { cout << s << ' '; });
  cout << endl;
}

int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  biggies(vec, 5);
  return 0;
}
