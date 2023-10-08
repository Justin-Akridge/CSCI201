#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h>
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
        cerr << "Password must contain atleast one digit and one uppercase letter\n";
      else if (!has_capital_letter)
        cerr << "Password must contain atleast one uppercase letter\n";
      else
        cerr << "Password must contain atleast one digit\n";
      
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

void write_new_account_to_file(int account_number) {
  account new_account;
  ofstream output_file;
  output_file.open("account.dat", ios::binary|ios::app);
  new_account.create_account();
  output_file.write(reinterpret_cast<char *>(&new_account), sizeof(account));
  output_file.close();
}

int main() {
  int number_of_accounts_in_bank; 
  int option = 0;
  do {
    system("cls");
    std::cout << "------Dashboard------\n"
              << "Press 1 Create account" 
              << "Press 2 Deposit account\n"
              << "Press 3 Withdraw account\n"
              << "Press 4 Check balance\n"
              << "Press 5 Display account\n"
              << "Press 6 Close account\n"
              << "Press 7 Modify account\n"
              << "Press 7 Quit\n";
    std::cin >> option;
    system("cls");
    int account_number;
    switch (option) {
      case 1:
        write_new_account_to_file(accounts_made);
        break;
      case 2:
        cout << "Enter your accounter number: ";
        cin >> account_number;
        break;
        case 3:
          new_account.withdraw();
          break;
        case 4:
          new_account.display();
          break;
        case 5:
          new_a
          break;
        default:
          std::cout << "Please enter a valid option [1-7]" << std::endl;
          break;
    }
  } while (option != 7);
} 

