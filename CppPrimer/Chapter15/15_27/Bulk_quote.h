#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote.h"
class Bulk_quote :public Disc_quote {
public:
    Bulk_quote( ) { std::cout << "Bulk_Quote constructor: default.\n"; }

    using Disc_quote::Disc_quote;

    Bulk_quote(const Bulk_quote & bq) :Disc_quote(bq) { std::cout << "Bulk_Quote copy constructor.\n"; }

    Bulk_quote(Bulk_quote && bq) :Disc_quote(std::move(bq)) { std::cout << "Bulk_Quote move constructor.\n"; }

    ~Bulk_quote( ) { std::cout << "Bulk_Quote deconstructor.\n"; }

    Bulk_quote &operator=(const Bulk_quote & rhs) {
        if(this != &rhs) {
            Disc_quote::operator=(rhs);
        }
        std::cout << "Blu_Quote copy=().\n";
        return *this;
    }

    Bulk_quote &operator=(Bulk_quote && rhs) {
        if(this != &rhs) {
            Disc_quote::operator=(std::move(rhs));
        }
        std::cout << "Blu_Quote move=().\n";
        return *this;
    }

    double net_price(std::size_t)const override;
    void debug( )const override;

};
#endif // !BULK_QUOTE_H
