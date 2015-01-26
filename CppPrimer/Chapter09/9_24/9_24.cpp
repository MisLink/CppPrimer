#include<vector>
#include<iostream>
using std::cout;
using std::endl;
using std::vector;
int main( ) {
    vector<int> vec;
    //Fault
    cout << vec.at(0) << endl;
    cout << vec[0] << endl;
    cout << vec.front( ) << endl;
    cout << *vec.begin( ) << endl;
    return 0;
}