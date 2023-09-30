#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
  Customer();
  //~Customer();
  int withdraw(double);
  void deposit(std::string&);
  double get_loan() const;
  std::string get_username() const;
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

#endif
