#include"15_07_Limit_quote.h"
#include<iostream>
double print_total(std::ostream &, const Quote &, size_t);

int main( ) {
    Quote q("aaa", 12.5);
    Limit_quote lq("aaa", 12.5, 10, 0.2);
    print_total(std::cout, q, 12);
    print_total(std::cout, lq, 12);
    return 0;
}


double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn( ) << " #sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
