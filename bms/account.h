#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
  Customer();
  ~Customer();
  Account(const Account &acct) {
  const int withdraw(const double);
  void deposit(const double);
  const double get_loan(const Account &acct) const;
  const std::string get_username() const;
  void set_username(const std::string&);
  void set_password(const std::string&);
  void reset_password(const std::string&);
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
