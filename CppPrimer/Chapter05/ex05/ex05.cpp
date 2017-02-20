#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
int main() {
  vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  unsigned grade;
  while (cin >> grade) {
    string grade_;
    if (grade < 60) {
      grade_ = scores[0];
    } else {
      grade_ = scores[(grade - 50) / 10];
      if (grade != 100) {
        if (grade % 10 > 7) {
          grade_ += "+";
        } else if (grade % 10 < 3) {
          grade_ += "-";
        }
      }
    }
    cout << grade_ << endl;
  }
  return 0;
}
