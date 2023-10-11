#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
public:
  //Account() : account_number({};
  Account(const int&);
  void set_name(const std::string&);
  void set_pin(const int&);
  void set_balance(const double&);
  void set_savings(const double&);
  void set_password(const std::string&);
  void set_username(const std::string& new_username);
  int get_pin() const; 
  int get_account_number() const;
  double get_savings() const;
  double get_balance() const;
  std::string get_username() const;
  std::string get_password() const;
  void show_account_details() const;
  void withdraw_from_savings(double& withdraw_amount);
  void withdraw_from_debit(double& withdraw_amount);
  void alert_balance();
private:
  std::string name;
  const int account_number;
  int pin;
  double balance;
  double savings;
  double credit;
  std::string username;
  std::string password;
  int credit_score;
};

#endif
