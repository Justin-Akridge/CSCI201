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

int display_menu() {
  std::cout << "
int main(){ 
  Bank bank;
  if (create_new_account_input() == "no") {
    // need to implement time function here 
    std::cout << "Have a great day.\n";
    exit(EXIT_SUCCESS); 
  } else {
    // [_] TODO: implement these functions
    Customer new_customer;
    std::cout << "Lets set up your account with a username and password.\n";
    new_customer.set_username();
    new_customer.set_password();
    std::cout << "Thank you for creating an account global bank.\n";
    int choice = display_menu();
    
  } 
}
