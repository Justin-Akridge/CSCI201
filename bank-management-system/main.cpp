#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Customer.h"
#include "Bank.h"

std::string create_new_account_input() {
  char response;
  while (true) {
    try {
      std::cout << "Would you like to create a account with the bank (y/n)? ";
      std::cin >> response;
      response = std::tolower(response);
      if (response == 'y') {
        return "yes";
      }
      else if (response == 'n') {
        return "no";
      } else {
        throw std::invalid_argument("Input must be equal to (y) for yes and (n) for no.");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    } catch (...) {
      std::cerr << "Something went wrong..Please try again.\n";
    }
  }
}

int get_menu_choice() {
  while (true) {
    try {
      char input;
      std::cout << "------Dashboard------\nPress 1 to make a deposit\nPress 2 to withdraw\n
                   Press 3 to make a payment\npress 4 to take out a loan\n";
      std::cin >> input;
      if (std::isdigit(input)) {
        switch (input) {
          case '1':
            return 1;
          case '2':
            return 2;
          case '3':
            return 3;
          case '4':
          default:
            throw std::out_of_range("Input must be a number between 1-4");
        }
      } else {
        throw std::invalid_argument("Input must be a number");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    } catch (std::out_of_range &e) {
      std::cerr << "Out of range: " << e.what() << '\n';
    } catch (...) {
      std::cerr << "Something else went wrong..\n";
    }
  }
}

int main(){ 
  Bank bank;
  if (create_new_account_input() == "no") {
    // need to implement time function here 
    std::cout << "Have a great day.\n";
    exit(EXIT_SUCCESS); 
  } else {
    // [_] TODO: implement these functions
    Customer customer;
    std::cout << "Lets set up your account with a username and password.\n";
    customer.set_username();
    customer.set_password();
    std::cout << "Thank you for creating an account global bank.\n";
    int choice = get_menu_choice();
    int status_code;
    switch (choice) {
      case 1:
        status_code = customer.deposit();
        if (status_code) {
          std::cout << "Would you like to enter a valid deposit (y/n)? ";
        }
        break;
      case 2:
        status_code = customer.withdraw();
        if (customer.get_balance() < 0) {
          customer.alert_balance();
        break;
      case 3:
        customer.payment();
        break;
      case 4:
        customer.get_a_loan();
        break;
    }
  } 
}
