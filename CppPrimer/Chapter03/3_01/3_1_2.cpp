#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
struct Sales_data {
    string no;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main( ) {
    Sales_data item;
    double price = 0.0;
    cin >> item.no >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    cout << item.no << ' ' << item.units_sold << ' ' << item.revenue << price << endl;
    return 0;
}