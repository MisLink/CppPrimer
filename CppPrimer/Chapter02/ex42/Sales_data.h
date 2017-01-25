#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
struct Sales_data {
  std::string no;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

#endif  // !SALES_DATA
