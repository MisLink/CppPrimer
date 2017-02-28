#include <iostream>
#include <string>
#include <utility>
#include <vector>
int main() {
  std::string str;
  int i;
  std::vector<std::pair<std::string, int>> vec;
  while (std::cin >> str >> i) {
    vec.push_back(std::make_pair(str, i));
    /*
    //vec.push_back(std::pair<std::string, int>(str, i));
    //vec.push_back({str, i});
    //std::pair<std::string, int> p{str, i};
    //vec.push_back(p);
    */
  }
  for (auto& x : vec) {
    std::cout << x.first << ' ' << x.second << std::endl;
  }
  return 0;
}
