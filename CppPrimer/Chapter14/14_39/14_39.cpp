#include<iostream>
#include<string>
#include<algorithm>
class test {
public:
    test(std::size_t l = 0, std::size_t h = 0) :low(l), high(h) { }
    bool operator()(const std::string & s) {
        if(s.size( ) >= low&&s.size( ) <= high) {
            return true;
        } else {
            return false;
        }
    }
private:
    std::size_t low;
    std::size_t high;
};

int main( ) {
    std::string str;
    test t(1, 9);
    int sum = 0;
    while(std::cin >> str) {
        if(t(str)) {
            sum++;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}