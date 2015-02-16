#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include<string>
int main( ) {
    //a
    std::vector<int> vec1{1, 2, 3, 1111, 2222, 3333};
    std::greater<int> gre;
    unsigned num = 0;
    for(auto & x : vec1) {
        if(gre(x, 1024)) {
            ++num;
        }
    }
    std::cout << num << std::endl;
    //b
    std::vector<std::string> vec2{"pooh", "pooh", "pooh", "abc"};
    std::not_equal_to<std::string> net;
    for(auto & x : vec2) {
        if(net(x, "pooh")) {
            std::cout << x << std::endl;
            break;
        }
    }
    //c
    std::multiplies<int> mul;
    std::vector<int> vec3{1, 2, 3, 4, 5, 6, 7};
    for(auto & x : vec3) {
        x = mul(x, 2);
    }
    for(auto & x : vec3) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    return 0;
}