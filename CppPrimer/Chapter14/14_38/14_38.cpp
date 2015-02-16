#include<iostream>
#include<string>
#include<algorithm>
class test {
public:
    test(std::size_t s = 0) :sz(s) { }
    bool operator()(const std::string & s) {
        if(s.size( ) == sz) {
            return true;
        } else {
            return false;
        }
    }
private:
    std::size_t sz;
};

int main( ) {
    std::string str;
    test t(2);
    int sum = 0;
    while(std::cin >> str) {
        if(t(str)) {
            sum++;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}