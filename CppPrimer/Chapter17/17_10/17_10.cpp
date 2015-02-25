#include<bitset>
#include<iostream>
int main( ) {
    std::bitset<32> b1;
    int a[ ] = {1, 2, 3, 5, 8, 13, 21};
    for(auto x : a) {
        b1.set(x);
    }
    std::bitset<32> b2;
    for(unsigned i = 0; i < 32; ++i) {
        b2[i] = b1[i];
    }
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    return 0;
}