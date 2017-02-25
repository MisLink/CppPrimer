#include "ex07.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
int main(int argc, char* argv[]) {
  ifstream open(argv[1]);
  ofstream output(argv[2]);
  Sales_data total;
  if (read(open, total)) {
    Sales_data trans;
    while (read(open, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(output, total) << std::endl;
        total = trans;
      }
    }
    print(output, total) << std::endl;
  } else {
    std::cerr << "No data" << std::endl;
  }
  return 0;
}
