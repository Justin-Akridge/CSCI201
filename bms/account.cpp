#include <iostream>
#include "account.h"

Account::Account() {
  name = "";
  account_number = 0;
  pin;
  balance;
  savings;
  credit;
  username;
  password;
  credit_score;
}

void show_account_details() const;
void withdraw();
void deposit(double);
void report() const;
int get_account_number() const;
double get_balance() const;

int Account::set_pin() {
  bool done = false;
  string pin;
  while (!done) {
    cout << "Enter a 4 digit pin for you account: ";
    cin >> pin;
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
      std::cerr << "Pin number must be 4 digits.\n";
    }
    if (valid_pin) {
      done = true;
    }
  }
  return stoi(pin);
}

double 
void Account::create_account(int account_number) {
  cout << "Enter the name of the account holder: ";
  string name;
  getline(name, 50);
  cin.ignore(256, '\n');
  char type;
  cout << "Would you like to create debit account or savings account?\n"
       << "Press 1 for debit"
       << "Press 2 for savings\n";
  cin >> type;
  if (type == '1') {
    char response;
    cout << "A minimum of $1000 is required to open an account. Is this okay? [y/n] ";
    cin >> response; 
    if (response == 'y') {
      cout << "How much would you like to desposit? ";
      double deposit_amount;
      cin >> deposit_amount;
      if (deposit_amount < 1000) {
      } else {
      
      }
    } else if (response == 'n') {

    }
  } else if (type == '2') {
    
  } else {
    cout << "Invalid input. Number is not equal to 1 or 2\n";
  }
}

const double Account::get_balance() const {
  return balance;
}

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

void Account::deposit(const double deposit) {
  balance += deposit;
}

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

void Account::set_password() {
  bool is_valid_username = false;
  bool done = false;
  std::string password_input;
  std::cout << "Enter your username: ";
  std::cin >> password_input;
  const std::hash<std::string> hasher;
  const auto hash_result = hasher(password_input);
  password = hash_result; 
}

void Account::set_username() {
  bool is_valid_username = false;
  bool done = false;
  std::string username_input;
  std::cout << "Enter your username: ";
  std::cin >> username_input;
  const std::hash<std::string> hasher;
  const auto hash_result = hasher(username_input);
  username = hash_result; 
}


double account::get_loan() const {
  double total_cash_in_bank = this->balance + this->savings;
  if (total_cash_in_bank >= 2000 && credit_score >= 300) {
    std::cout << cout << "Enter the amount of loan you want to withdraw: ";
    std::string loan_amount;
    std::cin >> loan_amount;
    double interest_rate;
    double max_loan_amount_from_bank = total_cash_in_bank * 10;

    //if (credit_score >= 800) {

    //} else if (credit_score >= 700) {
    //} else if (credit_score >= 600) {
    //} else if (credit_score >= 500) {
    //} else if (credit_score >= 400) {
    //} else if (credit_score >= 300) {
    //}
  } else {
    std::cerr << "Bank account must have atleast $2000 to pull out a loan. ";
                 "Your account only has " << total_cash_in_bank << " in the bank.";
  }
}

void Customer::reset_password();


void alert_balance() {
  std::cerr << "You have overdrawn your account. Your current balance is: "  << balance << '\n'; 
}
#endif
