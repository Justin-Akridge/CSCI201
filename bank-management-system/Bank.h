#ifndef BANK_H
#define BANK_H
#include <unordered_map>

class Bank {
public:
  Bank();
private:
  double balance;
  double credit_line;
  std::string unordered_map<int, int>;
};

Bank::Bank() {
  balance = 0.0;
  credit_line = 0.0;
  std::unordered_map<int, int> account;
}

#endif
