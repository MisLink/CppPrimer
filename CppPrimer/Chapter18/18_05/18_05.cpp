#include<iostream>
int main( ) {
    try {

    } catch(std::exception e) {
        std::cout << "exception" << std::endl;
        abort( );
    }
    return 0;
}