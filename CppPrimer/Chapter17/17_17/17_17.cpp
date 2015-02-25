#include<regex>
#include<iostream>
#include<string>
using std::string;
int main( ) {
    string pattern = "[[:alpha:]]*[^c]ei[[:alpha:]]*";
    std::regex r(pattern, std::regex::icase);
    string str;
    std::getline(std::cin, str);
    for(std::sregex_iterator i(str.begin( ), str.end( ), r), end; i != end; ++i) {
        std::cout << i->str( ) << std::endl;
    }

    return 0;
}