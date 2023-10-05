#include <iostream>
#include "account.h"
Account::Account(int number) : account_number(number) {
  //maybe implement temporary encripted username and password
  username = "";
  password = "";
  pin = 0000;
  balance = 1000;
  savings = 0.0;
  credit = 0.0;
  account_number;
}

Account::Account(int number, std::string init_first_name, std::string init_last_name, 
                 int init_pin, int init_balance) : account_number(number){
  // add in username and password
  first_name = init_first_name;
  last_name = init_last_name;
  pin = init_pin;
  balance = init_balance;
}

Account::Account(int number, std::string init_first_name, std::string init_last_name, int init_pin, 
                 int init_balance, double init_savings) : account_number(number) {
  // add in username and password
  first_name = init_first_name;
  last_name = init_last_name;
  pin = init_pin;
  balance = init_balance;
  savings = init_savings;
}

//void Account::create_account(const Account &a) {
//  std::cout << "Hello " << std::endl;
////  void set_username(const std::string&);
////  void set_password(const std::string&);
//}

void Account::set_first_name(std::string& fn) {
  first_name = fn;
}

void Account::set_last_name(std::string& ln) {
  last_name = ln;
}

void Account::set_pin(int& pin) {
  pin = pin;
}

void Account::set_balance(double& balance) {
  balance = balance;
}

void Account::set_savings(double& savings) {
  savings = savings;
}
#if 0

int Customer::withdraw(double withdraw_amount) {
  if (withdraw_amount <= 5) {
    std::cerr << "Withdraw amount must be greater then $5.00\n";
  } else if (withdraw_amount >= 5000) {
    std::cerr << "Withdraw amount exceeds the maximum withdraw amount."
                 "Please request a bank representative in the display menu to fulfill your request";
  } else if (balance - withdraw_amount < 100) {
    std::cerr << "Your request cannot be fulfilled. Your withdraw ammount exceeds the"
                 "amount in your balance.";
  } else {
    balance -= withdraw_amount;
  }
} 

bool validate_username(std::string username) {
  // TODO []figure this out bool contains_special character = true;
  bool contains_capital = false;
  bool contains_digit = false;
  for (auto i : username) {
    if (std::isalpha(i) || std::isdigit(i)) {
      if (i - 'a' > 65 && !contains_capital) {
        contains_capital = true;
      } else if (std::isdigit(i)) {
        contains_digit = true;
      }
    } else {
      return false;
    }
  }
  if (contains_digit && contains_capital) {
    return true;
  } else {
    return false;
  }
}

void Customer::set_username() {
  bool is_valid_username = false;
  bool done = false;
  std::string username_input;
  while (!done) {
    try {
      std::cout << "Enter your username: ";
      std::cin >> username_input;
      if (validate_username(username_input)) {
        is_valid_username = true;
        done = true;
      } else {
        throw std::invalid_argument("Input must be a digit or a character\n");
      }
    } catch (std::out_of_range &e) {
      std::cerr << "Out of range error: " << e.what() << '\n';
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument error: " << e.what() << '\n';
    }
  }
  const std::hash<std::string> hasher;
  const auto hash_result = hasher(username_input);
  username = hash_result; 
}

void Customer::deposit(std::string& deposit_ammount) {
  bool done = false;
  bool is_valid_int = true;
  while (!done) {
    for (int i= 0; i < deposit_ammount.size(); i++) {
      if (!std::isdigit(deposit_ammount[i])) {
        is_valid_int = false;   
      }
    }
    if (!is_valid_int) {
      std::cerr << "Input must be an integer\n";
    } else {
      done = true;
    }
    balance += std::stoi(deposit_ammount);
  }
}

double Customer::get_loan() const {
  double total_cash_in_bank = this->balance + this->savings;
  if (total_cash_in_bank >= 2000 && credit_score >= 300) {
    std::cout << cout << "Enter the amount of loan you want to withdraw: ";
    std::string loan_amount;
    std::cin >> loan_amount;
    double interest_rate;
    double max_loan_amount_from_bank = total_cash_in_bank * 10;

    if (credit_score >= 800) {

    } else if (credit_score >= 700) {
    } else if (credit_score >= 600) {
    } else if (credit_score >= 500) {
    } else if (credit_score >= 400) {
    } else if (credit_score >= 300) {
    }

  } else {
    std::cerr << "Bank account must have atleast $2000 to pull out a loan. ";
                 "Your account only has " << total_cash_in_bank << " in the bank.";
  }
}

void Customer::set_password();
void Customer::reset_password();

double Customer::get_balance() const {
  return balance;
}

void alert_balance() {
  std::cerr << "You have overdrawn your account. Your current balance is: "  << balance << '\n'; 
}
#endif
