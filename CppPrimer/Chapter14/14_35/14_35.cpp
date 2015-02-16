#include"14_35.h"
std::string InputString::operator()( ) {
    std::string str;
    std::getline(is, str);
    if(is) {
        return str;
    } else {
        return std::string( );
    }
}
