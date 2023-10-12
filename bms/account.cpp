#include <iostream>
#include <cstring>
#include <cassert>
#include <limits>
#include "account.h"

std::string Account::get_account_name() {
  std::cout << "Enter the name of the account holder: ";
  std::string name;
  std::getline(std::cin, name);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return name;
}

double get_initial_deposit() {
  bool done = false;
  double deposit_amount;
  std::cout << "You are required to make a $1000 deposit to open an account."
            << " Enter the amount you would like to deposit or -1 to quit: ";
  while (!done) {
    std::cin >> deposit_amount;
    if (deposit_amount >= 1000 || deposit_amount == -1) {
      done = true;
    } else {
      std::cerr << "Initial deposit must be greater then 1000$ to open an account." 
                << " Enter an amount greater than 1000 or -1 to quit: \n";
    }
  }
  return deposit_amount;
}

double get_savings_amount() {
  double savings;
  std::cout << "Enter the amount you would like to put in savings: ";
  std::cin >> savings;
  return savings;
}

int get_pin_input() {
  bool done = false;
  std::string pin;
  while (!done) {
    std::cout << "Enter a 4 digit pin for you account: ";
    std::cin >> pin;
    bool valid_pin = true;
    if (pin.size() == 4) {
      for (const auto &digit : pin) {
        if (!isdigit(digit)) {
          std::cerr << "Pin must contain only digits.\n";
          valid_pin = false;
          break;
        }
      }
    } else {
      valid_pin = false;
      std::cerr << "Pin number must be 4 digits.\n";
    }
    if (valid_pin) {
      done = true;
    }
  }
  return stoi(pin);
}

const auto Account::get_username() {
  bool done = false;
  std::string username;
  while (!done) {
    std::cout << "Please enter a 7-20 character username: ";
    std::cin >> username;
    if (username.size() >= 7 && username.size() <= 20) {
      done = true;
    } else if (username.size() < 7) {
      std::cerr << "Username must be atleast 7 characters long\n";
    } else {
      std::cerr << "Username must be atleast 20 characters long\n";
    }
  }
  
  //hash username
  const std::hash<std::string> hasher;
  const auto hash_result = hasher(username);
  std::cout << hash_result << std::endl;
  return hash_result;
}

const auto Account::get_password() {
  //get password
  while (true) {
    std::string password;
    std::cout << "Enter a password (password must be between 7 and 20 characters long"
              << " and contain a digit and capital letter: ";
    std::cin >> password;

    // check if username is valid but confirming 7-20 characters and contains a 
    // capital letter and number.
    bool contains_digit = false;
    bool contains_capital_letter = false;
    if (password.size() >= 7 && password.size() <= 20) {
      for (auto const &ch : password) {
        if (std::isdigit(ch)) {
          contains_digit = true;
        } else if(std::isupper(ch)) {
          contains_capital_letter = true; 
        }
      }
      //hash password before returning
      if (contains_digit && contains_capital_letter) {
        const std::hash<std::string> hasher;
        const auto hash_result = hasher(password);
        return hash_result;
      } else if (!contains_capital_letter && !contains_digit) {
        std::cerr << "Password must contain atleast one digit and one uppercase letter\n";
      } else if (!contains_digit) {
        std::cerr << "Invalid password: Password must contain atleast one digit.\n";
      } else {
        std::cerr << "Invalid password: Password must contain atleast one capital letter.\n";
      } 
    } else if (password.size() > 20) {
      std::cerr << "Invalid password: Password must be 20 or less characters\n";
    } else {
      std::cerr << "Invalid password: Password must be 7 or more characters\n";
    }
  }
}

int Account::create_account() {
  this->name = get_account_name();
  double initial_deposit = get_initial_deposit();
  if (initial_deposit == -1) {
    std::cerr << "Canceled account creation\n";
    return -1; 
  } else {
    this->balance = initial_deposit;
  }
  std::cout << "Would you like to make a deposit in your savings account: [y/n] ";
  char res;
  std::cin >> res;
  if (res == 'y') {
    this->savings = get_savings_amount(); 
  } 

  this->pin = get_pin_input();
  
  this->username = get_username();
  this->password = get_password();
  return 1;
}

void Account::serialize(std::ofstream& outfile) const {
  char buffer[sizeof(Account)];
  std::memcpy(buffer, this, sizeof(Account));
  outfile.write(buffer, sizeof(Account));
}

void Account::deserialize(std::ifstream& infile) const {
  //infile.read(reinterpret_cast<char*>(this), sizeof(Account));
  char buffer[sizeof(Account)];
  std::memcpy(buffer, this, sizeof(Account));
  infile.read(buffer, sizeof(Account));
}

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
