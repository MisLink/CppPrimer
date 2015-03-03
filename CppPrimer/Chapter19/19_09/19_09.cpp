#include<typeinfo>
#include<iostream>
using std::cout;
using std::endl;
class Base { };
class Derived :public Base { };
int main( ) {
    int arr[10];
    Derived d;
    Base *p = &d;
    cout << typeid(42).name( ) << endl <<
        typeid(arr).name( ) << endl <<
        typeid(std::string).name( ) << endl <<
        typeid(p).name( ) << endl <<
        typeid(*p).name( ) << endl;
    return 0;
}