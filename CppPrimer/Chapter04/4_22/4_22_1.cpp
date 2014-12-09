#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main( ) {
    unsigned grade;
    while (cin >> grade) {
        cout << ((grade >= 90) ? "high pass" : (grade >= 75) ? "low pass" : (grade >= 60) ? "pass" : "fail") << endl;
    }
    return 0;
}