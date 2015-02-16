#include"14_37.h"
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
int main( ) {
    std::vector<std::string> vec{"abc", "abc", "abc", "abcd"};
    std::for_each(vec.begin( ), vec.end( ), compare("abcd", "abcde"));
    for(auto & x : vec) {
        std::cout << x << std::endl;
    }
}