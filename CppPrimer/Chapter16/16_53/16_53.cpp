#include<iostream>
#include<string>

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

int main( ) {
    int i = 0;
    double d = 3.14;
    std::string s = "hello";
    char c = 'a';
    bool b = true;
    print(std::cout, i);
    std::cout << std::endl;
    print(std::cout, i, d);
    std::cout << std::endl;
    print(std::cout, i, d, s, c, b);
    std::cout << std::endl;
    return 0;
}