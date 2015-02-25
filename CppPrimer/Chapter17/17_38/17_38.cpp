#include<iostream>

int main( ) {
    char ch[10];
    while(std::cin.getline(ch, 10)) {
        std::cout << ch << std::endl;
    }
    return 0;
}