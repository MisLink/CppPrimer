#include <stack>
using std::stack;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main() {
  string str{"a+(b+c)+d"};
  stack<char> st;
  bool l = false;
  for (auto& c : str) {
    if (c == '(') {
      l = true;
    } else if (c == ')') {
      l = false;
    }
    if (l) {
      st.push(c);
    }
  }
  string result = "";
  while (!st.empty()) {
    if (st.top() != '(') {
      result = st.top() + result;
    }
    st.pop();
  }
  str.replace(str.find('('), str.find(')') - str.find('(') + 1, result);
  cout << str << endl;
  return 0;
}
