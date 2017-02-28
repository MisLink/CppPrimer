#include <iostream>
#include <map>
#include <string>
int main() {
  std::multimap<std::string, std::string> authors{
      {"JKRowing", "HarryPotter"},
      {"Lippman", "C++Primer"},
      {"Kernighan", "The C Programming Language"},
      {"JKRowing", "The Casual Vacancy"}};
  std::string author = "JKRowing";
  std::string work = "HarryPotter";
  auto found = authors.find(author);
  auto count = authors.count(author);
  while (count) {
    if (found->second == work) {
      found = authors.erase(found);
      count--;
    } else {
      found++;
      count--;
    }
  }
  for (auto& x : authors) {
    std::cout << x.first << ": " << x.second << std::endl;
  }
  return 0;
}
