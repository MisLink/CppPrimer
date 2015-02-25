#include<regex>
#include<iostream>
#include<string>
int main( ) {
    std::string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
    std::regex r(pattern);
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