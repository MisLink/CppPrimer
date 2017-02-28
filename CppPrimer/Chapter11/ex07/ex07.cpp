#include <string>
using std::string;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  map<string, vector<string>> familys;
  cout << "enter the last name: ";
  string lastName;
  while (cin >> lastName) {
    cout << "enter the child name: ";
    string childName;
    while (cin >> childName) {
      familys[lastName].push_back(childName);
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
