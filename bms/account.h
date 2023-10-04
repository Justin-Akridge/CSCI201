#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
  Customer();
  ~Customer();
  const int withdraw(double) const;
  const void deposit(std::string&) const;
  const double get_loan() const;
  const std::string get_username() const;
  const void set_username();
  const void set_password();
  const void reset_password();
  const double get_balance() const;
private:
  std::string username;
  std::string password;
  int credit_score;
  int pin;
  double balance;
  double savings;
  double credit;
};

#endif
