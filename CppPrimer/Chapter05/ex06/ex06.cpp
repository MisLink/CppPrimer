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
    grade_ = (grade < 60) ? scores[0] : grade_ = scores[(grade - 50) / 10];
    grade_ += (grade == 100 || grade < 60)
                  ? ""
                  : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
    cout << grade_ << endl;
  }
  return 0;
}
