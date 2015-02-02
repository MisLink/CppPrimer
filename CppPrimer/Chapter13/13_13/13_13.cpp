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
    //����
    X x;

    //��ֵ
    func(x);

    //������
    func_(x);

    //��̬����
    X * x_ = new X;

    //delete
    delete x_;

    //����
    vector<X> vec{X( ), X( ), X( )};
    return 0;
}