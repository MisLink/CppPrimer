#include <fstream>
#include <iostream>
#include <string>
#include "ex42_text_query.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;

void runQueries(std::ifstream& is) {
  TextQuery tq(is);
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q") {
      break;
    }
    print(cout, tq.query(s)) << endl;
  }
}
int main(int argc, char* argv[]) {
  std::ifstream ifs(argv[1]);
  runQueries(ifs);
  return 0;
}
