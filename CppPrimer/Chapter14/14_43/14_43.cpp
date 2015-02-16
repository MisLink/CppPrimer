#include<vector>
#include<functional>
#include<iostream>
#include<string>
int main( ) {
    std::modulus<int> mod;
    std::vector<int> vec{2, 3, 4};
    int num;
    while(std::cin >> num) {
        std::string ret = "yes\n";
        for(auto & x : vec) {
            if(mod(num, x)) {
                ret = "no\n";
                break;
            }
        }
        std::cout << ret;
    }
    return 0;
}