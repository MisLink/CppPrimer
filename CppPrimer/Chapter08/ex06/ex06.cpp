#include "ex06.h"
#include <fstream>
#include <iostream>
using std::ifstream;
int main(int argc, char* argv[]) {
  ifstream open(argv[1]);
  Sales_data total;
  if (read(open, total)) {
    Sales_data trans;
    while (read(open, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data" << std::endl;
  }
  return 0;
}
