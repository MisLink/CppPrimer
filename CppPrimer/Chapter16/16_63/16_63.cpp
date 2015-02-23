#include<iostream>
#include<vector>
#include<string>
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

int main( ) {
    std::vector<int> veci{1, 2, 2, 2, 3, 4, 5};
    std::cout << count(veci, 2) << std::endl;
    std::vector<double> vecd{1.1, 2.2, 3.3, 1.1};
    std::cout << count(vecd, 2.2) << std::endl;
    std::vector<std::string> vecs{"a", "b", "a", "b"};
    std::string s = "a";
    std::cout << count(vecs, s) << std::endl;
    return 0;
}