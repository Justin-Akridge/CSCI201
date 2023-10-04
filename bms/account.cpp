#include <iostream>
#include "Customer.h"

Account::Account() {
  //maybe implement temporary encripted username and password
  username = "";
  password = "";
  pin = 0000;
  balance = 1000;
  savings = 0.0;
  credit = 0.0;
}

Account::Account(string init_first_name, string init_last_name, const long &init_account_amount) {
  first_name = init_first_name;
  last_name = init_last_name;
  account_amount = init_account_amount;
}

Account::Account(const Account &a) {
  cumulative_account_amount = a->cumulative_account_amount;
  account_amount = a->account_amount;
  first_name = a->first_name;
  last_name = a->last_name;
  account_amount = a-> account_amount;
}

Customer::~Customer();

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

  std::string username;
  std::string password;
  int pin;
  double balance;
  double savings;
  double credit;
