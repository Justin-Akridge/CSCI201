#include <iostream>
#include <cctype>
#include <vector>
#include <limits>
#include <string>
#include <fstream>
#include <sqlite3.h>
#include "account.h"
using namespace std;


double get_balance() {
  double balance;
  cout << "Enter the amount you would like to put in into your spend account: ";
  cin >> balance;
  return balance;
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

Account write_new_account(Account &ac) {
  Account account = ac;
  ofstream output_file;
  output_file.open("account.dat", ios::binary|ios::app);
  if (account.create_account()) {
    account.serialize(output_file);
  }
  output_file.close();
  return account;
}

bool valid_pin(int pin) {
  Account account;
  bool flag=false;
  ifstream inFile;
  inFile.open("account.dat",ios::binary);
  if(!inFile) {
    cout<<"File could not be open !! Press any Key...";
    return false;
  }
  cout<<"\nBALANCE DETAILS\n";
  while(inFile.read(reinterpret_cast<char *> (&account), sizeof(account))) {
    cout << account.get_pin();
    if(account.get_pin() == pin){
      account.show_account_details();
      flag=true;
    }
  }
  inFile.close();
  if(flag==false) {
    cout<<"\n\nAccount number does not exist";
  }
}


void display_account(int account_number) {
  Account account;
  bool valid_account_number = false;
  std::ifstream infile;
  infile.open("account.dat", ios::binary);
  if (!infile) {
    std::cerr << "File could not be open. Press a key to return.";
    return;
  }

  while (infile.read(reinterpret_cast<char *>(&account), sizeof(account))) {
    if (account.get_account_number() == account_number) {
      account.show_account_details();
      valid_account_number = true;
    }
  }
  infile.close();
  if (!valid_account_number) {
    std::cerr << "Account does not exist!\n";
  }
}

int main() {
  int option = 0;
  do {
    std::cout << "\n------Dashboard------\n"
              << "Press 1 Create account\n" 
              << "Press 2 Deposit account\n"
              << "Press 3 Withdraw account\n"
              << "Press 4 Display account\n"
              << "Press 6 Close account\n"
              << "Press 7 Modify account\n"
              << "Press 8 Quit\n"
              << "\n-------Settings------\n"
              << "Press 9 Change password\n"
              << "Press 0 Change username\n\nEnter: ";
    std::cin >> option;
    Account new_account;
    switch (option) {
      case 1:
        new_account = write_new_account(new_account);
        break;
      case 2:
        {
          bool done = false;
          while (!done) {
            std::cout << "Enter account pin number: ";
            int pin;
            std::cin >> pin;
            if (new_account.get_pin() == pin) {
              double deposit_amount = get_deposit_ammount();
              done = true;
            } else {
              std::cerr << "Invalid pin number. Please re-enter account number.\n"; 
            }
          }
          break;
        }
      case 3:
        {
          bool done = false;
          double withdraw_amount = 0.0;
          while (!done) {
            std::cout << "Would you have like to withdraw from debit or savings?\n"
                      << "1 for debit\n2 for savings\n-1 to exit\nEnter: ";
            char res;
            std::cin >> res;
            std::cout << "Enter account pin number: ";
            int pin;
            std::cin >> pin;
            if (new_account.get_pin() == pin) {
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
            } else {
              std::cerr << "Invalid pin number. Please re-enter account number.\n"; 
            }
          }
          break;
        }
     case 4:
       {
         bool done = false;
         int pin;
         while (!done || pin == -1) {
           std::cout << "Enter account pin number or -1 to quit: ";
           std::cin >> pin;
           if (new_account.get_pin() == pin) {
             new_account.show_account_details();
           } else {
             std::cerr << "Invalid pin number. Please re-enter account number.\n"; 
           }
         } 
         break;
       }
     default:
       std::cout << "Please enter a valid option [1-7]" << std::endl;
       break;
    } 
  } while (option != 7);
}
