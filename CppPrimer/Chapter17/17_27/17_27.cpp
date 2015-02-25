#include<regex>
#include<string>
#include<iostream>
using std::string;
using namespace std::regex_constants;
bool valid(const std::smatch &s) {
    if(!s[3].matched) {
        return !s[2].matched;
    }
    if(s[2].matched) {
        return s[3].matched;
    }
    return true;
}
int main( ) {
    string code = "(\\d{5})(-)?(\\d{4})?";
    std::regex r(code);
    string str;
    string fmt = "$1-$3";
    while(std::getline(std::cin, str)) {
        std::cout << std::regex_replace(str, r, fmt) << std::endl;
    }
    return 0;
}