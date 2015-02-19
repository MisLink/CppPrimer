#include"15_05_Bulk_quote.h"
#include"15_07_Limit_quote.h"
int main( ) {
    Quote q("aaa", 12.5);
    Bulk_quote bq("bbb", 13.5, 10, 0.2);
    Limit_quote lq("ccc", 14.5, 10, 0.3);
    Quote &r1 = q;
    r1.debug( );
    std::cout << "----------------------\n";
    Quote &r2 = bq;
    r2.debug( );
    std::cout << "----------------------\n";
    Quote &r3 = lq;
    r3.debug( );
    std::cout << "----------------------\n";

    
    return 0;
}