#include "ex03.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data total;
  if (cin >> total.no >> total.units_sold >> total.revenue) {
    Sales_data trans;
    while (cin >> trans.no >> trans.units_sold >> trans.revenue) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        cout << total.no << endl;
        cout << total.units_sold << endl;
        cout << total.revenue << endl;
        total = trans;
      }
    }
    cout << total.no << endl;
    cout << total.units_sold << endl;
    cout << total.revenue << endl;
  } else {
    std::cerr << "no data" << endl;
    return -1;
  }
  return 0;
}
