#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
#include"Sales_data.h"
std::vector<Sales_data>::iterator less_than(std::vector<Sales_data> &vec, const double avg) {
    return std::find_if(vec.begin( ), vec.end( ), [avg](Sales_data &s) { return s.avg_price( ) < avg; });
}
int main( ) {
    std::vector<Sales_data> vec{Sales_data("c++", 10, 12.5), Sales_data("java", 8, 15.5)};
    auto it = less_than(vec, 130);
    std::cout << *it << std::endl;
    return 0;
}