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
};
unsigned Employee::idGenerator = 0;
