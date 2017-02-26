#include <deque>
#include <iostream>
#include <string>
using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  deque<string> deq;
  string str;
  while (cin >> str) {
    deq.push_back(str);
  }
  for (auto iter = deq.begin(); iter != deq.end(); ++iter) {
    cout << *iter << ' ';
  }
  cout << endl;
  return 0;
}
