#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::sort;
using std::unique_copy;
int main() {
  istream_iterator<int> input(cin);
  istream_iterator<int> eof;
  ostream_iterator<int> output(cout, " ");
  vector<int> vec(input, eof);
  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), output);
  return 0;
}
