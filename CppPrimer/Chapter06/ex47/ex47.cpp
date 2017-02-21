#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
//#define NDEBUG
void print(vector<int> v);
int main() {
  vector<int> v{1, 2, 3, 4, 5};
  print(v);
  cout << endl;
  return 0;
}
void print(vector<int> v) {
#ifdef NDEBUG
  cout << "vector size: " << v.size() << endl;
#endif
  if (!v.empty()) {
    auto temp = v.back();
    v.pop_back();
    print(v);
    cout << temp << " ";
  }
}
