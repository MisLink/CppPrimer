#include<iostream>
#include<string>
template<typename T>
void print(T &arr) {
    for(auto x : arr) {
        std::cout << x << ' ';
    }
}

int main( ) {
    std::string arr[ ] = {"aa", "bb", "cc", "dd", "ee"};
    print(arr);
    std::cout << std::endl;
    char ch[ ] = {'a', 'b', 'c', 'd', 'e'};
    print(ch);
    std::cout << std::endl;
    return 0;
}