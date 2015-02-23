#include<iostream>
#include<memory>
#include<string>
template<typename T, typename... Args>

std::shared_ptr<T> Make_shared(Args&&... args) {
    std::shared_ptr<T> ret(new T(std::forward<Args>(args)...));
    return ret;
}

int main( ) {
    auto p = Make_shared<std::string>(5, ' ');
    std::cout << *p << std::endl;
    return 0;
}