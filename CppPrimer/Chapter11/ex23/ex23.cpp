#include <string>
using std::string;
#include <map>
using std::multimap;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  multimap<string, string> familys;
  cout << "enter the last name: ";
  string lastName;
  while (cin >> lastName) {
    cout << "enter the child name: ";
    string childName;
    while (cin >> childName) {
      familys.insert({lastName, childName});
      cout << "enter the child name: ";
    }
    cin.clear();
    cout << "enter the last name: ";
  }

  for (auto& p : familys) {
    cout << p.first << ": \n";
    for (auto& x : p.second) {
      cout << x << endl;
    }
  }
  return 0;
}
