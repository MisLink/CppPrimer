#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
class Sales_data {
  friend std::istream& read(std::istream& is, Sales_data& item);
  friend std::ostream& print(std::ostream& os, const Sales_data& item);

 private:
  std::string no;
  unsigned units_sold = 0;
  double revenue = 0.0;

 public:
  std::string isbn() const { return no; }
  Sales_data& combine(const Sales_data& rhs);
  Sales_data() = default;
  Sales_data(const std::string& s) : no(s) {}
  Sales_data(const std::string& s, unsigned n, double p)
      : no(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream& is) { read(is, *this); }
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
std::istream& read(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.no >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

#endif  // !SALES_DATA
