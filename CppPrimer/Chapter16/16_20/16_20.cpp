#include<iostream>
#include<list>
template <typename T>
std::ostream &print(std::ostream & os, T &t) {
    for(auto i = t.begin( ); i != t.end( ); ++i) {
        os << *i << ' ';
    }
    return os;
}
int main( ) {
    std::list<int> li{1, 2, 3, 4, 5};
    print(std::cout, li);
    return 0;
}