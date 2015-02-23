#include"Sales_data.h"
#include<string>
using std::istream;
using std::ostream;

Sales_data::Sales_data(istream & is) :units_sold(0), revenue(0.0) {
    is >> *this;
}

double Sales_data::avg_price( )const {
    if(units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data & Sales_data::operator=(std::string & rhs) {
    bookNo = rhs;
    units_sold = 0;
    revenue = 0.0;
    return *this;
}
Sales_data & Sales_data::operator+=(const Sales_data & rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data & rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

istream & operator>>(istream & is, Sales_data & item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is) {
        item.revenue = item.units_sold*price;
    } else {
        item = Sales_data( );
    }
    return is;
}

ostream & operator<<(ostream & os, const Sales_data & item) {
    os << item.isbn( ) << " " << item.units_sold << " " << item.revenue << " " << item.avg_price( );
    return os;
}

istream & read(istream & is, Sales_data & item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold*price;
    return is;
}
ostream & print(ostream & os, const Sales_data & item) {
    os << item.isbn( ) << " " << item.units_sold << " " << item.revenue << " " << item.avg_price( );
    return os;
}
Sales_data add(const Sales_data & lhs, const Sales_data & rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

size_t std::hash<Sales_data>::operator()(const Sales_data &s)const {
    return std::hash<std::string>( )(s.bookNo) ^ std::hash<unsigned>( )(s.units_sold) ^ std::hash<double>( )(s.revenue);
}
