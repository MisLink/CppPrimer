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
#include <functional>
using std::bind;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz) { return s.size() < sz; }
void elimDups(vector<string>& vec) {
  sort(vec.begin(), vec.end());
  auto end_unique = unique(vec.begin(), vec.end());
  vec.erase(end_unique, vec.end());
}
void biggies(vector<string>& words, vector<string>::size_type sz) {
  elimDups(words);
  auto iter = partition(words.begin(), words.end(), bind(check_size, _1, sz));
  for_each(iter, words.end(), [](const string& s) { cout << s << ' '; });
  cout << endl;
}

int main() {
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  biggies(vec, 4);
  return 0;
}
