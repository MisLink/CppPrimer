#ifndef ACCOUNT
#define ACCOUNT
#include <string>
class Account {
 private:
  std::string owner;
  double amount;
  static double interestRate;
  static constexpr double todayRate = 3.14;
  static double initRate() { return todayRate; }

 public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double newRate) { interestRate = newRate; }
};
double Account::interestRate = initRate();
#endif  // !ACCOUNT
