#include<regex>
#include<iostream>
#include<string>
using std::string;
bool valid(const std::smatch &s) {
    if(s[1].matched) {
        return s[3].matched && ((s[4].matched == 0) || (s[4].str( ) == " "));
    } else {
        return !s[3].matched && (s[4].str( ) == s[6].str( ));
    }
}
int main( ) {
    string phone = "(\\()?(\\d{3})(\\))?([-. ])? +(\\d{3})([-. ])? +(\\d{4})";
    std::regex r(phone);
    string str;
    while(std::getline(std::cin, str)) {
        for(std::sregex_iterator i(str.begin( ), str.end( ), r), end; i != end; ++i) {
            if(valid(*i)) {
                std::cout << "valid number: " << i->str( ) << std::endl;
            } else {
                std::cout << "invalid number: " << i->str( ) << std::endl;
            }
        }
    }
    return 0;
}