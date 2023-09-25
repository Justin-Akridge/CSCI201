#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
  void withdraw();
  void deposit(double);
  double get_loan();
private:
  std::string username;
  std::string password;
  int pin;
  double balance;
  double savings;
  double credit;
};

#endif
