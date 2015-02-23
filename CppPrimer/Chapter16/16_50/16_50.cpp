#include<iostream>
using std::cout;
using std::endl;

template<typename T>
void f(T t) {
    cout << "f(T)" << endl;
}

template<typename T>
void f(const T *t) {
    cout << "f(const T *)" << endl;
}

template<typename T>
void g(T t) {
    cout << "g(T)" << endl;
}

template<typename T>
void g(T *t) {
    cout << "g(T *)" << endl;
}

int main( ) {
    int i = 42;
    int *p = &i;
    const int ci = 0;
    const int *cp = &ci;

    g(42);
    g(p);
    g(ci);
    g(cp);

    f(42);
    f(p);
    f(ci);
    f(cp);

    return 0;
}