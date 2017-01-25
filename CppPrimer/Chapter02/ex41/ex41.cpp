#include <iostream>
#include <string>

struct Sales_data {
  std::string no;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

void c_1_5_1() {
  Sales_data item;
  double price = 0.0;
  std::cin >> item.no >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  std::cout << item.no << ' ' << item.units_sold << ' ' << item.revenue << price
            << std::endl;
}
void c_1_5_2() {
  Sales_data item1, item2;
  double price1 = 0.0, price2 = 0.0;
  std::cin >> item1.no >> item1.units_sold >> price1;
  item1.revenue = price1 * item1.units_sold;
  std::cin >> item2.no >> item2.units_sold >> price2;
  item2.revenue = price2 * item2.units_sold;
  if (item1.no == item2.no) {
    unsigned totalCnt = item1.units_sold + item2.units_sold;
    double totalRevenue = item1.revenue + item2.revenue;
    std::cout << item1.no << ' ' << totalCnt << ' ' << totalRevenue << ' ';
    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "no sales" << std::endl;
    }
  } else {
    std::cerr << "not match" << std::endl;
  }
}
void c_1_6() {
  Sales_data item1, item2;
  double price;
  if (std::cin >> item1.no >> item1.units_sold >> price) {
    item1.revenue = item1.units_sold * price;
    while (std::cin >> item2.no >> item2.units_sold >> price) {
      item2.revenue = item2.units_sold * price;
      if (item1.no == item2.no) {
        item1.units_sold += item2.units_sold;
        item1.revenue += item2.revenue;
      } else {
        std::cout << item1.no << ' ' << item1.units_sold << ' ' << item1.revenue
                  << ' ';
        if (item1.units_sold != 0) {
          std::cout << item1.revenue / item1.units_sold << std::endl;
        } else {
          std::cout << "no sales" << std::endl;
        }
        item1.no = item2.no;
        item1.units_sold = item2.units_sold;
        item1.revenue = item2.revenue;
      }
    }
    std::cout << item1.no << ' ' << item1.units_sold << ' ' << item1.revenue
              << ' ';
    if (item1.units_sold != 0) {
      std::cout << item1.revenue / item1.units_sold << std::endl;
    } else {
      std::cout << "no sales" << std::endl;
    }
  }
}
int main() {
  c_1_5_1();
  c_1_5_2();
  c_1_6();
  return 0;
}
