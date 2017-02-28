#include <map>
using std::map;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
int main() {
  map<string, size_t> word_count;
  string word;
  while (cin >> word) {
    auto p = word_count.insert({word, 1});
    if (!p.second) {
      ++(p.first->second);
    }
  }
  for (const auto& w : word_count) {
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
  }
  return 0;
}
