#include<iostream>
#include<string>
#include<sstream>
template <typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str( );
}

template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if(p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str( );
}

std::string debug_rep(const std::string &s) {
    return "\"" + s + "\"";
}

template<>
std::string debug_rep(char * p) {
    return std::string(p);
}
template<>
std::string debug_rep(const char * p) {
    return std::string(p);
}

int main( ) {
    char * str = "abc";
    std::cout << debug_rep(str) << std::endl;
}