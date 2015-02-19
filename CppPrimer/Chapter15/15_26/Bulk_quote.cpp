#include"Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string & book, double p, std::size_t qty, double disc) :Disc_quote(book, p, qty, disc) {
    std::cout << "Bulk_Quote constructor: 4 parameters.\n";
}

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
