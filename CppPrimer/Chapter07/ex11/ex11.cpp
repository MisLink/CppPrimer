#include "ex11.h"
#include <iostream>
using std::cout;
using std::endl;
int main() {
  Sales_data item1;
  print(cout, item1) << endl;
  Sales_data item2("0-201-78345-X");
  print(cout, item2) << endl;
  Sales_data item3("0-201-78345-X", 4, 21.00);
  print(cout, item3) << endl;
  Sales_data item4(std::cin);
  print(cout, item4) << endl;
  return 0;
}
