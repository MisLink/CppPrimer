#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iostream>
int main( ) {
    std::vector<std::string> vec{"", "", "", "123"};
    auto count = std::count_if(vec.begin( ), vec.end( ), std::mem_fn(&std::string::empty));
    std::cout << count << std::endl;
    return 0;
}