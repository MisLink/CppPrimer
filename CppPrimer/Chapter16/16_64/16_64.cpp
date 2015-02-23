#include<iostream>
#include<vector>
#include<string>
#include<cstring>
template<typename T>
std::size_t count(const std::vector<T> &vec, T value) {
    std::size_t sum = 0;
    for(auto &x : vec) {
        if(x == value) {
            sum++;
        }
    }
    return sum;
}
template<>
std::size_t count(const std::vector<const char *> &vec, const char * value) {
    std::size_t sum = 0;
    for(auto &x : vec) {
        if(!strcmp(x, value)) {
            sum++;
        }
    }
    return sum;
}

int main( ) {
    std::vector<const char *> vecs{"a", "b", "a", "b"};
    std::cout << count(vecs, "a") << std::endl;
    return 0;
}