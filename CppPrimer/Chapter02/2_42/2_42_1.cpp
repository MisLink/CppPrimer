#include"Sales_data.h"
int main( ) {
    Sales_data item;
    double price = 0.0;
    std::cin >> item.no >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    std::cout << item.no << ' ' << item.units_sold << ' ' << item.revenue << ' ' << price << std::endl;
    return 0;
}