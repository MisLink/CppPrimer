#include<iostream>
template<typename T>
unsigned size(T &arr) {
    unsigned s = 0;
    for(auto x : arr) {
        s++;
    }
    return s;
}

int main( ) {
    int arr[ ] = {1, 2, 3, 4, 5};
    std::cout << size(arr);
    return 0;
}