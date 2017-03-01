#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::map;
using std::set;
int main(int argc, char* argv[]) {
  using line_no = vector<string>::size_type;
  std::ifstream is(argv[1]);
  string line;
  vector<string> file;
  map<string, set<line_no>> wm;
  while (std::getline(is, line)) {
    file.push_back(line);
    int n = file.size() - 1;
    std::istringstream iss(line);
    string word;
    while (iss >> word) {
      auto end = std::find_if(word.begin(), word.end(), ispunct);
      word.erase(end, word.end());
      wm[word].insert(n);
    }
  }
  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(std::cin >> s) || s == "q") {
      break;
    }
    auto found = wm.find(s);
    if (found != wm.end()) {
      std::cout << s << " occurs " << found->second.size() << " time(s). "
                << std::endl;
      for (auto& x : found->second) {
        std::cout << "(line " << x + 1 << ") " << file.at(x) << std::endl;
      }
    } else {
      std::cout << s << " occurs 0 time. " << std::endl;
    }
  }

  return 0;
}
