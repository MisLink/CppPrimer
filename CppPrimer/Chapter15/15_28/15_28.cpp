#include"Bulk_quote.h"
#include<vector>
int main( ) {
    std::vector<Quote> vec;
    for(unsigned i = 0; i < 10; ++i) {
        vec.push_back(Bulk_quote("a", 12.5, 10, 0.2));
    }
    double total = 0;
    for(auto & x : vec) {
        total += x.net_price(12);
    }
    std::cout << total << std::endl;
    return 0;
}