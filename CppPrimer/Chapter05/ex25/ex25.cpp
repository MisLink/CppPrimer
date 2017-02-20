#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
int main() {
  int a, b;
  while (cin >> a >> b) {
    try {
      if (b == 0) {
        throw runtime_error("divisor is 0.");
      }
      cout << static_cast<double>(a) / b << endl;
      break;
    } catch (runtime_error err) {
      cout << err.what() << endl;
      cout << "Try again? Enter y or n: \n";
      char c;
      cin >> c;
      if (c == 'y') {
        continue;
      } else if (c == 'n') {
        break;
      }
    }
  }
  return 0;
}
