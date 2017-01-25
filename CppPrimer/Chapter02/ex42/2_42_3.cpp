#include"Sales_data.h"
int main( ) {
    Sales_data item1, item2;
    double price;
    if(std::cin >> item1.no >> item1.units_sold >> price) {
        item1.revenue = item1.units_sold*price;
        while(std::cin >> item2.no >> item2.units_sold >> price) {
            item2.revenue = item2.units_sold*price;
            if(item1.no == item2.no) {
                item1.units_sold += item2.units_sold;
                item1.revenue += item2.revenue;
            }
            else {
                std::cout << item1.no << ' ' << item1.units_sold << ' ' << item1.revenue << ' ';
                if(item1.units_sold != 0) {
                    std::cout << item1.revenue / item1.units_sold << std::endl;
                }
                else {
                    std::cout << "no sales" << std::endl;
                }
                item1.no = item2.no;
                item1.units_sold = item2.units_sold;
                item1.revenue = item2.revenue;
            }
        }
        std::cout << item1.no << ' ' << item1.units_sold << ' ' << item1.revenue << ' ';
        if(item1.units_sold != 0) {
            std::cout << item1.revenue / item1.units_sold << std::endl;
        }
        else {
            std::cout << "no sales" << std::endl;
        }
    }
    return 0;
}