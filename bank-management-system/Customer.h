#pragma once
#include <string>

class Customer {
public:
  Customer();
  ~Customer();
  int withdraw(double);
  void deposit(double);
  double get_loan();
  void set_username();
  void set_password();
  void reset_password();
  double get_balance() const;
private:
  std::string username;
  std::string password;
  int pin;
  double balance;
  double savings;
  double credit;
};
