#include<iostream>
#include<vector>
#include<fstream>
#include<memory>

void exercise(int *b, int *e) {
    std::vector<int> v(b, e);
    //int *p = new int[v.size( )];
    std::shared_ptr<int> ptr(new int[v.size( )]);
    std::ifstream in("ints");

}

int main( ) {
    return 0;
}
