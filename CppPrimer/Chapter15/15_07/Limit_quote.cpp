#include"15_07_Limit_quote.h"

Limit_quote::Limit_quote(const std::string & book, double p, std::size_t qty, double disc) :Quote(book, p), max_qty(qty), discount(disc) { }

double Limit_quote::net_price(std::size_t n)const {
    if(n <= max_qty) {
        return n*(1 - discount)*price;
    } else {
        return max_qty*(1 - discount)*price + (n - max_qty)*price;
    }
}
