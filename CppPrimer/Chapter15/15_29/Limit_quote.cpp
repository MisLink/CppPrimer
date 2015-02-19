#include"Limit_quote.h"

Limit_quote::Limit_quote(const std::string & book, double p, std::size_t qty, double disc) :Disc_quote(book, p, qty, disc) { }

double Limit_quote::net_price(std::size_t n)const {
    if(n <= quantity) {
        return n*(1 - discount)*price;
    } else {
        return quantity*(1 - discount)*price + (n - quantity)*price;
    }
}

void Limit_quote::debug( )const {
    Quote::debug( );
    std::cout << "max qty: " << quantity << std::endl;
    std::cout << "discount: " << discount << std::endl;
}
