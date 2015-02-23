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

std::string debug_rep(char *p) {
    return std::string(p);
}

std::string debug_rep(const char *p) {
    return std::string(p);
}



template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    os << t;
    return os;
}
template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... args) {
    os << t << ',';
    return print(os, args...);
}

template<typename... Args>
std::ostream & errorMsg(std::ostream &os, const Args&... args) {
    return print(os, debug_rep(args)...);
}

int main( ) {
    errorMsg(std::cout, 1, 2, 3.14, "aaa", "ok");
    return 0;
}