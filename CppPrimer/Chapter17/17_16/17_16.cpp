#include<regex>
#include<iostream>
#include<string>
int main( ) {
    std::regex r("[^c]ei");
    std::string str;
    while(std::cin >> str) {
        if(std::regex_match(str, r)) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}