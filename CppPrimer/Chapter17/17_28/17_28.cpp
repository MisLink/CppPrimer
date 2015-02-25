#include<iostream>
#include<random>
unsigned random( ) {
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> u;
    return u(e);
}
int main( ) {
    std::cout << random( ) << std::endl;
    return 0;
}