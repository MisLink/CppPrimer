#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;
struct PersonInfo {
  string name;
  vector<string> phones;
};
bool vaild(const string& str) {
  if (str[0] == 0) {
    return false;
  } else {
    return true;
  }
}
string format(const string& str) {
  string temp = str.substr(0, 3) + '-' + str.substr(3, 3) + '-' + str.substr(6);
  return temp;
}
int main() {
  ifstream open(
      "D:\\document\\C++"
      "Projects\\CppPrimer\\CppPrimer\\Chapter08\\ex13\\sstream");
  string line, word;
  vector<PersonInfo> people;
  istringstream record;
  while (std::getline(open, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  for (const auto& entry : people) {
    ostringstream formatted, badNums;
    for (const auto& nums : entry.phones) {
      if (!vaild(nums)) {
        badNums << " " << nums;
      } else {
        formatted << " " << format(nums);
      }
    }
    if (badNums.str().empty()) {
      std::cout << entry.name << " " << formatted.str() << std::endl;
    } else {
      std::cerr << "input error: " << entry.name << " invailed number(s) "
                << badNums.str() << std::endl;
    }
  }

  return 0;
}
