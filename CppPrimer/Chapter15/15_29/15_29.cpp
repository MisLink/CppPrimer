#include"Bulk_quote.h"
#include<vector>
#include<memory>

int main( ) {
    std::vector<std::shared_ptr<Quote>> vec;
    for(unsigned i = 0; i < 10; ++i) {
        vec.push_back(std::make_shared<Bulk_quote>("a", 12.5, 10, 0.2));
    }
    double total = 0.0;
    for(auto & x : vec) {
        total += x->net_price(12);
    }
    std::cout << total << std::endl;
    return 0;
}