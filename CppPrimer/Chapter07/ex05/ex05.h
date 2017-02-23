#ifndef PERSON
#define PERSON
#include <string>
using std::string;
struct Person {
  string name;
  string address;
  string getName() const { return name; }
  string getAddress() const { return address; }
};
#endif  // !PERSON
