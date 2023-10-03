#include <vector>
#include <string>

class Account {
public:
  static vector<Accounts *> v_list;
  Account() : Account(getAccountNumber(), "", "", 0L) {};
  Account(const Account &a);
  void set_first_name(const string &first_name) const;
  void set_last_name(const string &last_name) const;
  void set_account_amount(const long &account_amount) const;
  const long &get_account_number() const;
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const long &get_account_amount() const;
  static long get_last_account_number();
  static vector<Account *> getAll();
private:
  static long cumulative_account_amount;
  long long account_amount;
  mutable string first_name;
  mutable string last_name;
  mutable long account_amount;
};
