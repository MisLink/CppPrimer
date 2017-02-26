#include <forward_list>
#include <iostream>
#include <string>
using std::string;
using std::forward_list;

void insert_value(forward_list<string>& fl, string first, string second) {
  auto prev = fl.before_begin();
  for (auto i = fl.begin(); i != fl.end(); i++) {
    if (*i == first) {
      fl.insert_after(i, second);
      return;
    }
    prev = i;
  }
  fl.insert_after(prev, second);
}
int main() {
  forward_list<string> fl{"123", "456", "789"};
  insert_value(fl, "111", "000");
  for (auto& x : fl) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
}
