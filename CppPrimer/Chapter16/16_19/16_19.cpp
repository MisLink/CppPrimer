#include<iostream>
#include<vector>
template<typename T>
std::ostream &print(std::ostream &os, T &t) {
    auto ret = t.begin( );
    for(T::size_type i = 0; i < t.size( ); ++i) {
        os << *ret++ << ' ';
    }
    return os;
}

int main( ) {
    std::vector<int> vec{1, 2, 3, 4, 5};
    print(std::cout, vec);
    return 0;
}