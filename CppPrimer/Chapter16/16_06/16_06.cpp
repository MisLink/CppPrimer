#include<iostream>
template<typename T, unsigned size>
T * begin(T(&arr)[size]) {
    return arr;
}
template<typename T, unsigned size>
T * end(T(&arr)[size]) {
    return arr + size;
}

int main( ) {
    int arr[ ] = {1, 2, 3, 4, 5};
    for(auto i = begin(arr); i != end(arr); ++i) {
        std::cout << *i << ' ';
    }
}