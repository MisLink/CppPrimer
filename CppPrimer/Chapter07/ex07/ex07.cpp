#include "ex07.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  Sales_data total;
  if (read(cin, total)) {
    Sales_data trans;
    while (read(cin, trans)) {
      if (total.isbn() == trans.isbn()) {
        add(total, trans);
      } else {
        print(cout, total);
        cout << endl;
        total = trans;
      }
    }
    print(cout, total);
    cout << endl;
  } else {
    std::cerr << "no data" << endl;
    return -1;
  }
  return 0;
}
