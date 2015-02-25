#include<iostream>
#include<random>
unsigned random(unsigned seed) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> u;
    return u(e);
}
int main( ) {
    unsigned seed;
    std::cin >> seed;
    std::cout << random(seed) << std::endl;
    return 0;
}