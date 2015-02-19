#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include"15_05_Quote.h"
class Limit_quote :public Quote {
public:
    Limit_quote( ) = default;
    Limit_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t)const override;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};
#endif // !LIMIT_QUOTE_H

