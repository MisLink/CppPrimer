#include<iostream>
#include"14_35.h"
#include<vector>
int main( ) {
    InputString input;
    std::vector<std::string> vec;
    while(true) {
        std::string s = input( );
        if(s == "") {
            break;
        }
        vec.push_back(s);
    }
    for(const auto & x : vec) {
        std::cout << x << std::endl;
    }
    return 0;
}