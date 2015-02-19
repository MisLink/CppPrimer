#ifndef BASKET_H
#define BASKET_H
#include<memory>
#include"Bulk_quote.h"
#include<set>
class Basket {
public:
    void add_item(const Quote & sale) {
        items.insert(std::shared_ptr<Quote>(sale.clone( )));
    }
    void add_item(Quote && sale) {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone( )));
    }
    double total_receipt(std::ostream &)const;
private:
    class compare {
    public:
        bool operator() (const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
            return lhs->isbn( ) < rhs->isbn( );
        }
    };
    std::multiset<std::shared_ptr<Quote>, compare> items;

};
#endif