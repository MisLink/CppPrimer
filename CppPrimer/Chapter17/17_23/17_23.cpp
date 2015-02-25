#include<regex>
#include<string>
#include<iostream>
using std::string;

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
    while(std::getline(std::cin, str)) {
        for(std::sregex_iterator i(str.begin( ), str.end( ), r), end; i != end; ++i) {
            if(valid(*i)) {
                std::cout << i->str( ) << std::endl;
            }
        }
    }
    return 0;
}