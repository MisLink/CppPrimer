#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main( ) {
    unsigned grade;
    while (cin >> grade) {
        if (grade >= 90) {
            cout << "high pass" << endl;
        }
        else if (grade >= 75) {
            cout << "low pass" << endl;
        }
        else if (grade >= 60) {
            cout << "pass" << endl;
        }
        else {
            cout << "fail" << endl;
        }
    }
    return 0;
}