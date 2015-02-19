#include"Bulk_quote.h"

double Bulk_quote::net_price(std::size_t n)const {
    if(n >= quantity) {
        return n*(1 - discount)*price;
    } else {
        return n*price;
    }
}

void Bulk_quote::debug( )const {
    Quote::debug( );
    std::cout << "min qty: " << quantity << std::endl;
    std::cout << "discount: " << discount << std::endl;
}
