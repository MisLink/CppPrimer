#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <algorithm>
using std::for_each;
int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  ofstream out1(argv[2]);
  ofstream out2(argv[3]);
  istream_iterator<int> input(in);
  istream_iterator<int> eof;
  ostream_iterator<int> output1(out1, " ");
  ostream_iterator<int> output2(out2, "\n");
  for_each(input, eof, [&output1, &output2](int i) {
    if (i % 2) {
      output1 = i;
    } else {
      output2 = i;
    }
  });
}
