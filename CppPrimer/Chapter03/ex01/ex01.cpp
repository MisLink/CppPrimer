#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void section_1_4_1() {
  int v = 50, sum = 0;
  while (v <= 100) {
    sum += v;
    v++;
  }
  cout << sum << endl;
}

void section_2_6_2() {
  struct Sales_data {
    string no;
    unsigned units_sold = 0;
    double revenue = 0.0;
  };
  Sales_data item;
  double price = 0.0;
  cin >> item.no >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  cout << item.no << ' ' << item.units_sold << ' ' << item.revenue << ' '
       << price << endl;
}

int main() {
  section_1_4_1();
  section_2_6_2();
  return 0;
}
