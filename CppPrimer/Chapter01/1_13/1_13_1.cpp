#include<iostream>
int main( ) {
    int sum = 0;
    for(int v = 50; v <= 100; v++) {
        sum += v;
    }
    std::cout << sum << std::endl;
    return 0;
}