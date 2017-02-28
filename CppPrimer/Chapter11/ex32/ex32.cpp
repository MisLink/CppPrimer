#include <iostream>
#include <map>
#include <set>
#include <string>
int main() {
  std::multimap<std::string, std::string> authors{
      {"JKRowing", "HarryPotter"},
      {"Lippman", "C++Primer"},
      {"Kernighan", "TheCProgrammingLanguage"},
      {"JKRowing", "TheCasualVacancy"}};
  std::map<std::string, std::set<std::string>> order;
  for (auto& x : authors) {
    order[x.first].insert(x.second);
  }
  for (auto& x : order) {
    std::cout << x.first << ": ";
    for (auto& y : x.second) {
      std::cout << y << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
