#include<iostream>
#include<string>
struct Sales_data {
    std::string no;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main( ) {
    Sales_data item;
    double price = 0.0;
    std::cin >> item.no >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    std::cout << item.no << ' ' << item.units_sold << ' ' << item.revenue << price << std::endl;
    return 0;
}