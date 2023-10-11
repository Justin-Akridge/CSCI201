#include <iostream>
#include <cassert>
#include "account.h"

Account::Account(const int &init_account_number) : account_number(init_account_number) {}

void Account::set_pin(const int& pin) {
  assert(pin >= 1000 && pin <= 9999);
  this->pin = pin;
}

void Account::set_balance(const double& init_balance) {
  assert(init_balance > 0);
  balance = init_balance;
}

void Account::set_name(const std::string& init_name) {
  name = init_name;
}

void Account::set_savings(const double& init_savings) {
  assert(init_savings > 0);
  savings = init_savings;
}

int Account::get_pin() const {
  return pin;
} 

int Account::get_account_number() const {
  return account_number;
}

double Account::get_savings() const {
  return savings;
}

double Account::get_balance() const {
  return balance;
}

void Account::withdraw_from_savings(double& withdraw_amount) {
  savings = withdraw_amount;
}

void Account::withdraw_from_debit(double& withdraw_amount) {
  balance -= withdraw_amount;
  if (withdraw_amount <= 5) {
    std::cerr << "Withdraw amount must be greater then $5.00\n";
  } else if (withdraw_amount >= 5000) {
    std::cerr << "Withdraw amount exceeds the maximum withdraw amount."
                 "Please request a bank representative in the display menu to fulfill your request";
  } else if (balance - withdraw_amount < 100) {
    std::cerr << "Your request cannot be fulfilled. Your withdraw ammount exceeds the"
                 "available balance. Your current balance is: " << balance << '\n';
  }
}

void Account::show_account_details() const {
  std::cout << "-----Account details-----\n"
       << "Name: " << this->name << '\n'
       << "Account number: " << this->account_number << '\n'
       << "Balance: " << this->balance << '\n'
       << "Savings: " << this->savings << '\n'
       << "Credit: " << this->credit << '\n';
}

void Account::set_password(const std::string& new_password) {
  assert(new_password.size() >= 7 && new_password.size() <= 20);
  bool contains_capital_letter = false;
  bool contains_digit = false;
  for (const auto &letter : new_password) {
    if (std::isupper(letter)) {
      contains_capital_letter = true;
    } else if (std::isdigit(letter)) {
      contains_digit = true;
    }
  }
}

void Account::set_username(const std::string& new_username) {
  bool is_valid_username = false;
  bool done = false;
  std::string username_input;
  std::cout << "Enter your username: ";
  std::cin >> username_input;
  const std::hash<std::string> hasher;
  const auto hash_result = hasher(username_input);
  username = hash_result; 
}


//double account::get_loan() const {
//  double total_cash_in_bank = this->balance + this->savings;
//  if (total_cash_in_bank >= 2000 && credit_score >= 300) {
//    std::cout << cout << "Enter the amount of loan you want to withdraw: ";
//    std::string loan_amount;
//    std::cin >> loan_amount;
//    double interest_rate;
//    double max_loan_amount_from_bank = total_cash_in_bank * 10;
//
//    //if (credit_score >= 800) {
//
//    //} else if (credit_score >= 700) {
//    //} else if (credit_score >= 600) {
//    //} else if (credit_score >= 500) {
//    //} else if (credit_score >= 400) {
//    //} else if (credit_score >= 300) {
//    //}
//  } else {
//    std::cerr << "Bank account must have atleast $2000 to pull out a loan. ";
//                 "Your account only has " << total_cash_in_bank << " in the bank.";
//  }
//}

void Account::alert_balance() {
  std::cerr << "You have overdrawn your account. Your current balance is: "  << this->balance << '\n'; 
}
