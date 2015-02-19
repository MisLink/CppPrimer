#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote.h"
class Bulk_quote :public Disc_quote {
public:
    Bulk_quote( ) { }
    Bulk_quote(const std::string &, double, std::size_t, double);

    Bulk_quote(const Bulk_quote & bq) :Disc_quote(bq) { }

    Bulk_quote(Bulk_quote && bq) :Disc_quote(std::move(bq)) { }

    Bulk_quote &operator=(const Bulk_quote & rhs);
    Bulk_quote &operator=(Bulk_quote && rhs);

    double net_price(std::size_t)const override;
    void debug( )const override;

    Bulk_quote * clone( )const override;
    Bulk_quote * clone( )override;

    ~Bulk_quote( ) override = default;
};
#endif // !BULK_QUOTE_H
