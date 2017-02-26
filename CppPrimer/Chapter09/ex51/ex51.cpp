#include <string>
using std::string;
#include <iostream>
using std::ostream;
using std::endl;
using std::cout;
class Date {
 private:
  unsigned year;
  unsigned month;
  unsigned day;

 public:
  Date(string s);
  ostream& print(ostream& os) {
    os << "year: " << year << endl;
    os << "month: " << month << endl;
    os << "day: " << day << endl;
    return os;
  }
};

Date::Date(string s) {
  unsigned format;
  if (s.find('/') != string::npos) {
    format = 0;
  } else if (s.find(',') != string::npos) {
    format = 1;
  }

  switch (format) {
    case 0:
      month = stoi(s.substr(0, s.find_first_of('/')));
      day = stoi(s.substr(s.find_first_of('/') + 1,
                          s.find_last_of('/') - s.find_first_of('/') - 1));
      year = stoi(s.substr(s.find_last_of('/') + 1, 4));
      break;
    case 1:
      if (s.find("Jan") != string::npos) {
        month = 1;
      } else if (s.find("Feb") != string::npos) {
        month = 2;
      } else if (s.find("Mar") != string::npos) {
        month = 3;
      } else if (s.find("Apr") != string::npos) {
        month = 4;
      } else if (s.find("May") != string::npos) {
        month = 5;
      } else if (s.find("Jun") != string::npos) {
        month = 6;
      } else if (s.find("Jul") != string::npos) {
        month = 7;
      } else if (s.find("Aug") != string::npos) {
        month = 8;
      } else if (s.find("Sep") != string::npos) {
        month = 9;
      } else if (s.find("Oct") != string::npos) {
        month = 10;
      } else if (s.find("Nov") != string::npos) {
        month = 11;
      } else if (s.find("Dec") != string::npos) {
        month = 12;
      }

      day = stoi(s.substr(s.find_first_of("0123456789"),
                          s.find(',') - s.find_first_of("0123456789")));

      year = stoi(s.substr(s.find(',') + 1, 4));
      break;
  }
}

int main() {
  Date date1("January 1,1900");
  date1.print(cout);
  Date date2("1/1/1900");
  date2.print(cout);
  Date date3("Jan 1,1900");
  date3.print(cout);
  return 0;
}
