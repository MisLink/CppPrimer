#include <iostream>
#include <string>
class Employee {
 public:
  static unsigned idGenerator;
  std::string name;
  unsigned id;

 public:
  Employee() : name(""), id(++idGenerator) {}
  Employee(const std::string& s) : name(s), id(++idGenerator) {}
  Employee(const Employee& e) : name(e.name), id(++idGenerator) {}
  Employee& operator=(const Employee& e) {
    name = e.name;
    id = ++idGenerator;
    return *this;
  }
};
unsigned Employee::idGenerator = 0;
