#include <iostream>
#include "Sales_item.h"
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator;
#include <algorithm>
using std::sort;
using std::find_if;
#include <numeric>
using std::accumulate;

int main() {
  istream_iterator<Sales_item> input(cin);
  istream_iterator<Sales_item> eof;
  vector<Sales_item> vec(input, eof);
  sort(vec.begin(), vec.end(), compareIsbn);
  for (auto beg = vec.begin(), end = beg; beg != vec.end(); beg = end) {
    end = find_if(beg, vec.end(), [beg](Sales_item& item) {
      return item.isbn() != beg->isbn();
    });
    cout << accumulate(beg, end, Sales_item(beg->isbn())) << endl;
  }
  return 0;
}
