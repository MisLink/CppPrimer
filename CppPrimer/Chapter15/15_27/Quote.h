#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
class Quote {
public:
    Quote( ) { std::cout << "Quote constructor: default.\n"; }
    Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { std::cout << "Quote constructor: 2 parameters.\n"; }
    Quote(const Quote & q) :bookNo(q.bookNo), price(q.price) { std::cout << "Quote copy constructor.\n"; }
    Quote(Quote && q) :bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote move constructor.\n"; }

    Quote &operator=(const Quote & rhs) {
        if(this != &rhs) {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote copy=().\n";
        return *this;
    }
    Quote & operator=(Quote && rhs) {
        if(this != &rhs) {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "Quote move=().\n";
        return *this;
    }

    std::string isbn( )const { return bookNo; }
    virtual double net_price(std::size_t n)const { return n*price; }
    virtual void debug( )const;

    virtual ~Quote( ) { std::cout << "Quote destructor.\n"; }
protected:
    double price = 0.0;
private:
    std::string bookNo;
};



#endif // !QUOTE_H
