#include "Account.h"

static vector<Accounts *> v_list;

Account::Account(string first_name, string last_name, const long &account_amount) {
  first_name = first_name;
  last_name = last_name;
  account_amount = account_amount;
}

Account(const long &account_num, string first_name, string last_name, const long &acct_amt) {
  acc
}

Account() : Account(getAccountNumber(), "", "", 0L) {};
Account(const Account &a);
void set_first_name(const string &fn) const;
void set_last_name(const string &ln) const;
void set_account_amount(const long &account_amt) const;
const long &get_account_number() const;
const std::string &get_first_name() const;
const std::string &get_last_name() const;
const long &get_account_amount() const;
static long get_last_account_number();
static vector<Account *> getAll();

  static long cumulative_account_amount;
  long long account_amount;
  mutable string first_name;
  mutable string last_name;
  mutable long account_amount;
