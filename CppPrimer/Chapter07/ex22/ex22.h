#ifndef PERSON
#define PERSON
#include <string>
using std::string;
using std::istream;
using std::ostream;
class Person {
  friend istream& read(istream& is, Person& person);
  friend ostream& print(ostream& os, Person& person);

 private:
  string name;
  string address;

 public:
  string getName() const { return name; }
  string getAddress() const { return address; }
  Person() = default;
  Person(const string& s1, const string& s2) : name(s1), address(s2) {}
  Person(istream& is) { read(is, *this); }
};
istream& read(istream& is, Person& person) {
  is >> person.name >> person.address;
  return is;
}
ostream& print(ostream& os, Person& person) {
  os << person.name << " " << person.address;
  return os;
}
#endif  // !PERSON
