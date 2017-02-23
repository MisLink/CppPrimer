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
  Sales_data(const std::string& s, unsigned n, double p)
      : no(s), units_sold(n), revenue(p * n) {
    std::cout << "Sales_data(const std::string&, unsigned, double)"
              << std::endl;
  }
  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "Sales_data( )" << std::endl;
  };
  Sales_data(const std::string& s) : Sales_data(s, 0, 0) {
    std::cout << "Sales_data(const std::string&)" << std::endl;
  }
  Sales_data(std::istream& is) : Sales_data() {
    std::cout << "Sales_data(istream &is)" << std::endl;
    read(is, *this);
  }
  inline double avg_prive() const;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
inline double Sales_data::avg_prive() const {
  if (units_sold > 0) {
    return revenue / units_sold;
  } else {
    return 0;
  }
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
