#include<iostream>

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f1(int & lhs, int &rhs) {
    std::cout << lhs << ' ' << rhs << std::endl;
}

void f2(int &&lhs, int &&rhs) {
    int a = lhs;
    int b = rhs;
    std::cout << a << ' ' << b << std::endl;
}

int main( ) {
    int a = 1;
    int b = 2;
    flip(f1, a, b);
    flip(f2, 1, 2);
}