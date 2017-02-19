#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::vector;
using std::string;
using std::endl;
int main() {
  vector<int> v1;
  cout << "v1:\n";
  cout << "size: ";
  cout << v1.size();
  cout << "\nvalue: ";
  for (auto i = v1.begin(); i != v1.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<int> v2(10);
  cout << "v2:\n";
  cout << "size: ";
  cout << v2.size();
  cout << "\nvalue: ";
  for (auto i = v2.begin(); i != v2.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<int> v3(10, 42);
  cout << "v3:\n";
  cout << "size: ";
  cout << v3.size();
  cout << "\nvalue: ";
  for (auto i = v3.begin(); i != v3.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<int> v4{10};
  cout << "v4:\n";
  cout << "size: ";
  cout << v4.size();
  cout << "\nvalue: ";
  for (auto i = v4.begin(); i != v4.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<int> v5{10, 42};
  cout << "v5:\n";
  cout << "size: ";
  cout << v5.size();
  cout << "\nvalue: ";
  for (auto i = v5.begin(); i != v5.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<string> v6{10};
  cout << "v6:\n";
  cout << "size: ";
  cout << v6.size();
  cout << "\nvalue: ";
  for (auto i = v6.begin(); i != v6.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  vector<string> v7{10, "hi"};
  cout << "v7:\n";
  cout << "size: ";
  cout << v7.size();
  cout << "\nvalue: ";
  for (auto i = v7.begin(); i != v7.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  return 0;
}
