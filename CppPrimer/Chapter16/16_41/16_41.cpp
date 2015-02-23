#include<iostream>

template<typename T>
auto sum(T lhs, T rhs)->decltype(lhs + rhs) {
    return lhs + rhs;
}
int main( ) {
    std::cout << sum(1234567890123456789, 1234567890123456789);
    return 0;
}