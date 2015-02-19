#include"Basket.h"
int main( ) {
    Basket basket;
    for(unsigned i = 0; i < 20; ++i) {
        basket.add_item(Bulk_quote("CLRS", 12.5, 10, 0.2));
    }
    for(unsigned i = 0; i < 20; ++i) {
        basket.add_item(Bulk_quote("C++Primer", 22.5, 15, 0.25));
    }
    for(unsigned i = 0; i < 20; ++i) {
        basket.add_item(Bulk_quote("CSAPP", 25.5, 8, 0.15));
    }
    basket.total_receipt(std::cout);
    return 0;
}