#include"Quote.h"

void Quote::debug( )const {
    std::cout << "bookNo: " << bookNo << std::endl;
    std::cout << "price: " << price << std::endl;
}

Quote &Quote::operator=(const Quote & rhs) {
    if(this != &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
    }
    return *this;
}
Quote &Quote::operator=(Quote && rhs) {
    if(this != &rhs) {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);
    }
    return *this;
}