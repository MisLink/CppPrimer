#include"Basket.h"
double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn( ) << " #sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
double Basket::total_receipt(std::ostream & os)const {
    double sum = 0;
    for(auto i = items.begin( ); i != items.end( ); i = items.upper_bound(*i)) {
        sum += print_total(os, **i, items.count(*i));
    }
    os << "total sale: " << sum << std::endl;
    return sum;
}