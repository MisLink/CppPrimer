#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
struct Sales_data {
  std::string no;
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string isbn() const { return no; }
  Sales_data& combine(const Sales_data& rhs);
};
Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
#endif  // !SALES_DATA
