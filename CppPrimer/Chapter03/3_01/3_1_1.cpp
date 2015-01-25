#include<iostream>
using std::cout;
using std::endl;
int main( ) {
    int v = 50, sum = 0;
    while(v <= 100) {
        sum += v;
        v++;
    }
    cout << sum << endl;
    return 0;
}