#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
public:
  const int get_account_number(); 
  void set_account_number(); 
  void create_account(const Account&);
  //static vector<Accounts *> account_list;
  Account(int);
  Account(int, std::string, std::string, int, int);
  Account(int, std::string, std::string, int, int, double);
  const int withdraw(const double);
  void deposit(const double);
  const double get_loan(const Account &acct) const;
  const std::string get_username() const;
  void set_username(const std::string&);
  void set_password(const std::string&);
  void reset_password(const std::string&);
  const double get_balance() const;
private:
  std::string first_name;
  std::string last_name;
  const int account_number;
  std::string username;
  std::string password;
  int credit_score;
  int pin;
  double balance;
  double savings;
  double credit;
};

#endif
