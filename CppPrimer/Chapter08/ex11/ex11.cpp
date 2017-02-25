#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::istringstream;
struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  string line, word;
  vector<PersonInfo> people;
  istringstream record;
  while (std::getline(std::cin, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  for (auto& x : people) {
    std::cout << "name: " << x.name << std::endl;
    for (auto& p : x.phones) {
      std::cout << "phones: " << p << std::endl;
    }
  }
  return 0;
}
