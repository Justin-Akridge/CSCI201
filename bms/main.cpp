#include <iostream>
#include <vector>
#include <string>
#include "Account.h"


int main() {
  while (true) {
    int option = 0;
    int *const option = &option;
    while (*option != 7) {
    std::cout << "------Dashboard------\n"
              << "Press 1 to open an account\n"
              << "Press 2 to check balance\n"
              << "Press 3 make a deposit\n"
              << "Press 4 to withdraw\n"
              << "Press 5 to close an account\n"
              << "Press 6 to display account\n";
              << "Press 7 to quit\n";
    std::cin >> *option;
    switch (*option) {
      case 1:
        Account::open();
        break;
      case 2:
        Account::balance();
        break;
      case 3:
        Account::deposit();
        break;
      case 4:
        Account::withdraw();
        break;
      case 5:
        Account::close();
        break;
      case 6:
        Account::display();
        break;
      case 7: {
        Account::ledgerDump();
        Vector<Account *>::iterator itr;
        for (itr = Account::v_list.begin(); itr != Account::v_list.end(); itr++) {
          delete *itr;
        }
        std::cout << "Have a good day! Goodbye!" << std::endl;
        break;
      }
      default:
        std::cout << "Please enter a valid option [1-7]" << std::endl;
        break;
    } 
    delete option;
  }
}
