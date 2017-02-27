#include "ex17.h"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;

int main() {
  Sales_data s1("a"), s2("aa"), s3("aaa"), s4("b"), s5("bbbb");
  vector<Sales_data> vec{s1, s2, s3, s4, s5};
  sort(vec.begin(), vec.end(), [](const Sales_data& s1, const Sales_data& s2) {
    return s1.isbn().size() < s2.isbn().size();
  });
  for (auto& x : vec) {
    print(std::cout, x);
    std::cout << std::endl;
  }

  return 0;
}
