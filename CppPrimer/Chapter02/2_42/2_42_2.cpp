#include"Sales_data.h"
int main( ) {
    Sales_data item1, item2;
    double price1 = 0.0, price2 = 0.0;
    std::cin >> item1.no >> item1.units_sold >> price1;
    item1.revenue = price1*item1.units_sold;
    std::cin >> item2.no >> item2.units_sold >> price2;
    item2.revenue = price2*item2.units_sold;
    if(item1.no == item2.no) {
        unsigned totalCnt = item1.units_sold + item2.units_sold;
        double totalRevenue = item1.revenue + item2.revenue;
        std::cout << item1.no << ' ' << totalCnt << ' ' << totalRevenue << ' ';
        if(totalCnt != 0) {
            std::cout << totalRevenue / totalCnt << std::endl;
        }
        else {
            std::cout << "no sales" << std::endl;
        }
        return 0;
    }
    else {
        std::cerr << "not match" << std::endl;
        return -1;
    }
}