#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
class Quote {
public:
    Quote( ) { }
    Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) { }

    Quote(const Quote & q) :bookNo(q.bookNo), price(q.price) { }
    Quote(Quote && q) :bookNo(std::move(q.bookNo)), price(std::move(q.price)) { }

    Quote &operator=(const Quote & rhs);
    Quote & operator=(Quote && rhs);

    std::string isbn( )const { return bookNo; }
    virtual double net_price(std::size_t n)const { return n*price; }
    virtual void debug( )const;

    virtual Quote * clone( )const { return new Quote(*this); }
    virtual Quote * clone( ) { return new Quote(std::move(*this)); }

    virtual ~Quote( ) { };
protected:
    double price = 0.0;
private:
    std::string bookNo;
};



#endif // !QUOTE_H
