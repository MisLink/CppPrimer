#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void ex1() {
  unsigned grade;
  while (cin >> grade) {
    cout << ((grade >= 90)
                 ? "high pass"
                 : (grade >= 75) ? "low pass" : (grade >= 60) ? "pass" : "fail")
         << endl;
  }
}

void ex2() {
  unsigned grade;
  while (cin >> grade) {
    if (grade >= 90) {
      cout << "high pass" << endl;
    } else if (grade >= 75) {
      cout << "low pass" << endl;
    } else if (grade >= 60) {
      cout << "pass" << endl;
    } else {
      cout << "fail" << endl;
    }
  }
}
int main() {
  // ex1();
  ex2();
  return 0;
}
