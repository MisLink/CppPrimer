#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include"Quote.h"
class Disc_quote :public Quote {
public:
    Disc_quote( ) { }
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) { }

    Disc_quote(const Disc_quote & dq) :Quote(dq), quantity(dq.quantity), discount(dq.discount) { }

    Disc_quote(Disc_quote && dq) :Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) { }

    Disc_quote &operator=(const Disc_quote & rhs) {
        if(this != &rhs) {
            Quote::operator=(rhs);
            quantity = rhs.quantity;
            discount = rhs.discount;
        }
        return *this;
    }

    Disc_quote &operator=(Disc_quote && rhs) {
        if(this != &rhs) {
            Quote::operator=(std::move(rhs));
            quantity = std::move(rhs.quantity);
            discount = std::move(rhs.discount);
        }
        return *this;
    }

    double net_price(std::size_t)const = 0;
    Disc_quote * clone( )const = 0;
    Disc_quote * clone( ) = 0;

    ~Disc_quote( )override = default;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
#endif
