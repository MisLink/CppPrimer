#include "ex13.h"
int main() {
  Sales_data total(std::cin);
  if (total.isbn() != "") {
    std::istream& is = std::cin;
    while (is) {
      Sales_data trans(is);
      if (total.isbn() == trans.isbn()) {
        add(total, trans);
      } else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
  } else {
    std::cerr << "no data" << std::endl;
    return -1;
  }
  return 0;
}
