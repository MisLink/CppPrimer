#include <functional>
using std::bind;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::find_if;
#include <iostream>
using std::cout;
using std::endl;
using namespace std::placeholders;
bool check_size(const string& s, string::size_type sz) { return s.size() < sz; }
int main() {
  string str("hello");
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
  cout << *iter << endl;
  return 0;
}
