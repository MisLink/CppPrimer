#include <iostream>
using std::cout;
using std::endl;
#include <functional>
using std::bind;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;
using namespace std::placeholders;

bool longer_than_6(const string& s) { return s.size() > 6; }
int main() {
  auto function = bind(longer_than_6, _1);
  vector<string> vec{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  cout << count_if(vec.begin(), vec.end(), function) << endl;
  return 0;
}
