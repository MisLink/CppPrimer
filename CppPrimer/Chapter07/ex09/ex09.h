#ifndef PERSON
#define PERSON
#include <string>
using std::string;
using std::istream;
using std::ostream;
struct Person {
  string name;
  string address;
  string getName() const { return name; }
  string getAddress() const { return address; }
};
istream& read(istream& is, Person& person) {
  is >> person.name >> person.address;
  return is;
}
ostream& print(ostream& os, const Person& person) {
  os << person.name << " " << person.address;
  return os;
}
#endif  // !PERSON
