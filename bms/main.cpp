#include <iostream>
#include <cctype>
#include <vector>
#include <limits>
#include <string>
#include <sqlite3.h>
#include "account.h"
using namespace std;

std::string get_account_name() {
  std::cout << "Enter the name of the account holder: ";
  std::string name;
  std::getline(std::cin, name);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return name;
}

std::string get_first_name() {
  cout << "Enter you first name: ";
  string first_name;
  cin >> first_name; 
  return first_name;
}

std::string get_last_name() {
  cout << "Enter you last name: ";
  string last_name;
  cin >> last_name; 
  return last_name;
}


double get_balance() {
  double balance;
  cout << "Enter the amount you would like to put in into your spend account: ";
  cin >> balance;
  return balance;
}

double get_savings() {
  double savings;
  cout << "Enter the amount you would like to put in savings: ";
  cin >> savings;
  return savings;
}

// TODO [] All of these functions come from account class and need  to be implemented
// in main.cpp
//
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
double get_initial_deposit() {
  bool done = false;
  double deposit_amount;
  std::cout << "You are required to make a $1000 deposit to open an account."
            << " Enter the amount you would like to deposit or -1 to quit: ";
  while (!done) {
    std::cin >> deposit_amount;
    if (deposit_amount == -1) {
      return -1;
    }
    if (deposit_amount >= 1000) {
      done = true;
    } else {
      std::cerr << "Initial deposit must be greater then 1000$ to open an account." 
                << " Enter an amount greater than 1000 or -1 to quit: \n";
    }
  }
  return deposit_amount;
}

const auto get_username() {
  bool done = false;
  std::string username;
  while (!done) {
    cout << "Please enter a 7-20 character username: ";
    cin >> username;
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

const auto get_password() {
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
   
int get_pin() {
  bool done = false;
  string pin;
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


double get_withdraw_amount() {
  bool done = false;
  double withdraw_amount = -1;
  while (!done) {
    std::cout << "Enter the amount you would like to withdraw: ";
    std::cin >> withdraw_amount;
    std::cout << "Do you want to withdraw $" << withdraw_amount << "? [y/n] ";
    char res;
    std::cin >> res;
    if (res == 'y') {
      return withdraw_amount;
    } else {
      std::cout << "Would you like to enter a new amount? [y/n] ";
      std::cin >> res;
      if (res == 'y') {
        continue; 
      } else {
        return -1;
      }
    }
  }
  return withdraw_amount;
}

double get_deposit_ammount() {
  cout << "Enter the amount you would like to deposit: ";
  double deposit;
  cin >> deposit;
  return deposit;
}

string get_username_login() {
  string username;
  cout << "Please enter your username and password\n";
  cout << "Username: ";
  cin >> username;
  return username;
}

string get_password_login() {
  string password;
  cout << "Password: ";
  cin >> password;
  return password;
}

void write_new_account_to_file(int account_number, Account&) {
  Account new_account(account_number);

  // TODO [] implement file writing
  //ofstream output_file;
  //output_file.open("account.dat", ios::binary|ios::app);
  //new_account.create_account();
  //output_file.write(reinterpret_cast<char *>(&new_account), sizeof(account));
  //output_file.close();
}

int main() {
  int number_of_accounts_in_bank = 0;
  int option = 0;
  do {
    std::cout << "\n------Dashboard------\n"
              << "Press 1 Create account\n" 
              << "Press 2 Deposit account\n"
              << "Press 3 Withdraw account\n"
              << "Press 4 Check balance\n"
              << "Press 5 Display account\n"
              << "Press 6 Close account\n"
              << "Press 7 Modify account\n"
              << "Press 8 Quit\n"
              << "\n-------Settings------\n"
              << "Press 9 Change password\n"
              << "Press 0 Change username\n\nEnter: ";
    std::cin >> option;
    Account new_account(number_of_accounts_in_bank);
    switch (option) {
      case 1:
        {
          //set name
          std::string full_name = get_account_name();
          new_account.set_name(full_name);
          double initial_deposit = get_initial_deposit();
          if (initial_deposit == -1) {
            break;
          } 
          
          // get the initial deposits for the account
          new_account.set_balance(initial_deposit);
          std::cout << "Would you like to make a deposit in your savings account: [y/n] ";
          char res;
          std::cin >> res;
          if (res == 'y') {
            double savings_amount = get_savings(); 
            new_account.set_savings(savings_amount);
          } 
          // set pin number for account
          int pin = get_pin();
          new_account.set_pin(pin);
          
          // get the username and password for account
          const auto username = get_username();
          const auto password = get_password();
          number_of_accounts_in_bank++;
          write_new_account_to_file(number_of_accounts_in_bank, new_account);
          break;
        }
      case 2:
        {
          bool done = false;
          while (!done) {
            std::cout << "Enter account pin number: ";
            int pin;
            std::cin >> pin;
            if (pin == new_account.pin) {
              double deposit_amount = get_deposit_ammount();
              done = true;
            } else {
              std::cerr << "Invalid pin number. Please re-enter account number.\n"; 
            }
          }
        }
        break;
      case 3:
        {
          bool done = false;
          double withdraw_amount = 0.0;
          while (!done) {
            std::cout << "Would you have like to withdraw from debit or savings?\n"
                      << "1 for debit\n2 for savings\n-1 to exit\nEnter: ";
            char res;
            std::cin >> res;
            if (res == '1') {
              done = true;
              withdraw_amount = get_withdraw_amount();
              new_account.withdraw_from_debit(withdraw_amount);
            } else if (res == '2') {
              done = true;
              withdraw_amount = get_withdraw_amount();
              new_account.withdraw_from_savings(withdraw_amount);
            } else {
              std::cerr << "Input is invalid response. Please try again..\n";
            }
          }
          break;
        }
      case 4:
        new_account.show_account_details();
        break;
      default:
        std::cout << "Please enter a valid option [1-7]" << std::endl;
        break;
    }
  } while (option != 7);
}
