#include<iostream>
#include<random>
unsigned random(unsigned seed, unsigned min, unsigned max) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}
int main( ) {
    unsigned seed;
    std::cin >> seed;
    unsigned min, max;
    std::cin >> min >> max;
    std::cout << random(seed, min, max) << std::endl;
    return 0;
}