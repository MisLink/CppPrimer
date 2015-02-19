#include"15_05_Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string & book, double p, std::size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(std::size_t n)const {
    if(n >= min_qty) {
        return n*(1 - discount)*price;
    } else {
        return n*price;
    }
}
