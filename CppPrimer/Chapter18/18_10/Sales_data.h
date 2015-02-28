#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
#include"Sales_data_exception.h"
class Sales_data {
    friend std::ostream & operator<<(std::ostream &, const Sales_data &);
    friend std::istream & operator>>(std::istream &, Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::ostream & print(std::ostream &, const Sales_data &);
    friend std::istream & read(std::istream &, Sales_data &);
public:
    Sales_data( ) :units_sold(0), revenue(0.0) { }
    Sales_data(const std::string & s) :bookNo(s), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string & s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);

    std::string isbn( )const { return bookNo; }
    Sales_data & operator+=(const Sales_data &);
    Sales_data & operator=(std::string &);

    operator std::string( ) const { return bookNo; }
    operator double( )const { return revenue; }
private:
    double avg_price( )const;
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

inline bool compareIsbn(const Sales_data & lhs, const Sales_data & rhs) {
    return lhs.isbn( ) < rhs.isbn( );
}
inline bool operator==(const Sales_data & lhs, const Sales_data & rhs) {
    return lhs.isbn( ) == rhs.isbn( ) &&
        lhs.units_sold == rhs.units_sold &&
        lhs.revenue == rhs.revenue;
}
inline bool operator!=(const Sales_data & lhs, const Sales_data & rhs) {
    return !(lhs == rhs);
}

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream & print(std::ostream &, const Sales_data &);
std::istream & read(std::istream &, const Sales_data &);

Sales_data operator+(const Sales_data &, const Sales_data &);
std::ostream & operator<<(std::ostream &, const Sales_data &);
std::istream & operator>>(std::istream &, Sales_data &);

#endif // !SALES_DATA_H
