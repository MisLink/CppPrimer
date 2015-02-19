#include<iostream>
#include"15_03.h"
double print_total(std::ostream &, const Quote &, size_t);
int main( ) {
    return 0;
}
double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn( ) << " #sold: " << n << " total due: " << ret << std::endl;
    return ret;
}