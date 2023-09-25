#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
  Customer();
  ~Customer();
  void withdraw();
  void deposit(double);
  double get_loan();
  void set_username();
  void set_password();
  void reset_password();
private:
  std::string username;
  std::string password;
  int pin;
  double balance;
  double savings;
  double credit;
};

#endif
