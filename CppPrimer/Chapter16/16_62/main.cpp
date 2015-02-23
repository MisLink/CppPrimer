#include"Sales_data.h"
#include<unordered_set>

int main( ) {
    std::unordered_multiset<Sales_data> mset;
    Sales_data sd("C++", 10, 12.5);
    mset.insert(sd);
    mset.emplace("Java", 6, 11.5);
    for(auto x : mset) {
        std::cout << x.isbn( ) << ": " << std::hash<Sales_data>( )(x) << std::endl;
    }
}