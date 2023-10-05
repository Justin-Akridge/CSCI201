#include <iostream>
#include <vector>
#include <string>
#include "account.h"
using namespace std;

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

int get_pin() {
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

std::string get_password() {
  bool done = false;
  string password;
  while (!done) {
    cout << "Please enter a 7-20 characters password with one digit and one uppercase letter: ";
    cin >> password;
    if (password.size() >= 7 && password.size() <= 20) {
      bool has_capital_letter = false;
      bool has_digit = false;
      for (const auto& letter : password) {
        if (isdigit(letter)) {
          has_digit = true;
        } else if (isupper(letter)) {
          has_capital_letter = true;
        }
      }
      if (has_capital_letter && has_digit)
        done = true;
      else if (!has_capital_letter && !has_digit)
        cerr << "Password must contain atleast one digit and one uppercase letter";
      else if (!has_capital_letter)
        cerr << "Password must contain atleast one uppercase letter";
      else
        cerr << "Password must contain atleast one digit";
      
    } else if (password.size() < 7) {
      cerr << "Password must must atleast 7 characters long\n";
    } else {
      cerr << "Password must be less then 21 characters long\n";
    }
  }
  return password;
}

std::string get_username() {
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
  return username;
}

int main() {
  int number_of_accounts = 0;
  std::cout << "Welcome to the bank!\n"
            << "Do you have an account? [y/n]: ";
  char input;
  std::cin >> input;
  input = std::tolower(input);
  if (input == 'y') {
    string username;
    string password;
    cout << "Please enter your username and password\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> pasword;

  } else if (input == 'n') {
    Account new_account(number_of_accounts);
    std::string first_name = get_first_name();
    std::string last_name = get_last_name();
    int pin = get_pin();
    double balance = get_balance();
    double savings = get_savings();
    std::string username = get_username();
    std::string password = get_password();
    number_of_accounts++;
  }
  while (true) {
    int option = 0;
    int *const option = &option;
    while (*option != 6) {
    std::cout << "------Dashboard------\n"
              << "Press 1 to check balance\n"
              << "Press 2 make a deposit\n"
              << "Press 3 to withdraw\n"
              << "Press 4 to close an account\n"
              << "Press 5 to display account\n";
              << "Press 6 to quit\n";
    std::cin >> *option;
      switch (*option) {
        case 1:
          new_account.get_balance();
          break;
//        case 2:
//          Account::deposit();
//          break;
//        case 3:
//          Account::withdraw();
//          break;
//        case 4:
//          Account::close();
//          break;
//        case 5:
//          Account::display();
//          break;
//        case 6: {
//          Account::ledgerDump();
//          Vector<Account *>::iterator itr;
//          for (itr = Account::v_list.begin(); itr != Account::v_list.end(); itr++) {
//            delete *itr;
//          }
//          std::cout << "Have a good day! Goodbye!" << std::endl;
//          break;
//        }
//        default:
//          std::cout << "Please enter a valid option [1-6]" << std::endl;
//          break;
      } 
      delete option;
    }
  }
  }
} 

