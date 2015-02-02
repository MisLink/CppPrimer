#include<vector>
using std::vector;
#include<iostream>
using std::cout;
using std::endl;
struct X {
    X( ) { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X &)" << endl; }
    X & operator=(const X & x) {
        cout << "operator=(const X &)" << endl;
        return *this;
    }
    ~X( ) {
        cout << "~X()" << endl;
    }
};
void func(X x) {

}
void func_(X & x) {

}
int main( ) {
    //构造
    X x;

    //传值
    func(x);

    //传引用
    func_(x);

    //动态分配
    X * x_ = new X;

    //delete
    delete x_;

    //容器
    vector<X> vec{X( ), X( ), X( )};
    return 0;
}