#include<regex>
#include<string>
#include<iostream>
using std::string;

int main( ) {
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    std::regex r(phone);
    string str;
    string fmt = "$2.$5.$7";
    while(std::getline(std::cin, str)) {
        std::cout << std::regex_replace(str, r, fmt) << std::endl;
    }
    return 0;
}