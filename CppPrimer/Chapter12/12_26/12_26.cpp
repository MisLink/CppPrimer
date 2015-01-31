#include<memory>
#include<string>
#include<iostream>
int main( ) {
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(5);
    std::string str;
    auto q = p;
    while(std::cin >> str) {
        alloc.construct(q++, str);
    }
    while(p != q) {
        std::cout << *(--q) << std::endl;
    }
    alloc.deallocate(p, 5);
    return 0;
}