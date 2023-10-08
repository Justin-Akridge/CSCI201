#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
public:
  void set_pin();
  int get_pin() const; 
  void create_account();
  void show_account_details() const;
  void withdraw();
  void deposit(double);
  void report() const;
  int get_account_number() const;
  double get_balance() const;
private:
  string name;
  const int account_number;
  int pin;
  double balance;
  double savings;
  double credit;
  //std::string username;
  //std::string password;
  //int credit_score;
};

#endif
