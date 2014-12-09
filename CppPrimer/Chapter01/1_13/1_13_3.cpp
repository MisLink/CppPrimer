#include<iostream>
int main( ) {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if(v1 > v2) {
        for(int i = v1; i >= v2; i--) {
            std::cout << i << ' ';
        }
    }
    else {
        for(int i = v1; i <= v2; i++) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}