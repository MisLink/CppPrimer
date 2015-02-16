#include<map>
#include<string>
#include<functional>
#include<iostream>
int add(int lhs, int rhs) {
    return lhs + rhs;
}
auto mod = [ ](int lhs, int rhs) {return lhs%rhs; };
class Div {
public:
    int operator()(int lhs, int rhs) {
        return lhs / rhs;
    }
};

int main( ) {
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>( )},
        {"*", [ ](int lhs, int rhs) {return lhs*rhs; }},
        {"/", Div( )},
        {"%", mod}
    };
        std::cout << "please enter a espression: ";
        int lhs, rhs;
        std::string s;
        while(std::cin >> lhs >> s >> rhs) {
        std::cout << binops[s](lhs, rhs) << std::endl;
        std::cout << "please enter a espression: ";
    }
    return 0;
}