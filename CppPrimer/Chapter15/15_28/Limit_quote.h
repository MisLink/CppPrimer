#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include"Disc_quote.h"
class Limit_quote :public Disc_quote {
public:
    Limit_quote( ) = default;
    Limit_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t)const override;
    void debug( )const override;

};
#endif // !LIMIT_QUOTE_H

