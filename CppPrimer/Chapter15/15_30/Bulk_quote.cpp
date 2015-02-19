#include"Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string & book, double p, std::size_t qty, double disc) :Disc_quote(book, p, qty, disc) { }

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

Bulk_quote * Bulk_quote::clone( )const {
    return new Bulk_quote(*this);
}

Bulk_quote * Bulk_quote::clone( ) {
    return new Bulk_quote(std::move(*this));
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote & rhs) {
    if(this != &rhs) {
        Disc_quote::operator=(rhs);
    }
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote && rhs) {
    if(this != &rhs) {
        Disc_quote::operator=(std::move(rhs));
    }
    return *this;
}
