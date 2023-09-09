/*
 * Justin Akridge
 * 09/09/2023
 * The problem collects data on users computers and its stores it in memory, and then it will display on the information in a formatted string
 */
#include "personal_computer.h"
#include <iostream>
#include <ios>
#include <limits>
#include <cctype>
#include <vector>

std::string get_manufacturer() {
  std::string manufacturer;
  std::cout << "Enter the computers manufacturer: ";
  std::cin >> manufacturer;
  return manufacturer;
}

std::string get_form_factor() {
  char form_factor;
  while (true) {
    try {
      std::cout << "Select one the following form factors:\n1 for desktop\n2 for laptop\nselection: ";
      std::cin >> form_factor;
      switch(form_factor) {
        case '1':
          return "desktop";
        case '2':
          return "laptop";
        default:
          throw std::invalid_argument("input is not equal to 1 or 2.");
      }
    } catch (std::invalid_argument &e) {
      std::cout << "Invalid argument: " << e.what() << "\n\n";
    }
  }
}

std::string get_serial_number() {
  std::string serial_number;
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter the serial number: ";
      std::cin >> serial_number;
      if (serial_number.size() > 10 && serial_number.size() < 30) {
        done = true;
      } else if (serial_number.size() <= 10 ) {
          throw std::out_of_range("input must be greater then 10 characters.");
      } else if (serial_number.size() >= 30) { 
          throw std::out_of_range("input must be less then 30 characters.");
      } else {
          throw std::invalid_argument("input is not valid");
      }
    } catch (std::out_of_range &e) {
      std::cerr << "Out of range error: " << e.what() << "\n\n";
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return serial_number;
}

std::string get_processor() {
  char processor;
  while (true) {
    try {
      std::cout << "Select one of the following processors:\n1 for i3\n2 for i5\n" 
                   "3 for i7\n4 for ryzen 3\n5 for ryzen 5\n6 for ryzen 7\nselection: ";
      std::cin >> processor;
      switch (processor) {
        case '1':
          return "i3";
        case '2':
          return "i5";
        case '3':
          return "i7";
        case '4':
          return "ryzen3";
        case '5':
          return "ryzen7";
        default:
          throw std::invalid_argument(" is not a selection.");
      }
    } catch (std::invalid_argument &e) {
      std::cout << "\nInvalid argument: " << processor << e.what() << "\n\n"; 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int get_ram() {
  char ram;
  while (true) {
    try {
      std::cout << "Select the storage amount of ram:\n1 for 4\n2 for 6\n3 for 8\n"
                   "4 for 16\n5 for 32\n6 for 64\nselection: ";
      std::cin >> ram; 
      switch (ram) {
        case '1':
          return 4;
        case '2':
          return 6;
        case '3':
          return 8;
        case '4':
          return 16;
        case '5':
          return 32;
        case '6':
          return 64;
        default:
          throw std::invalid_argument("input is not a valid selection");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n"; 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

std::string get_storage_type() {
  char storage_type;
  while (true) {
    try {
      std::cout << "Select storage type:\n1 for ssd\n2 for hdd\n"
                   "3 for cd\n4 for dvd\nselection: ";
      std::cin >> storage_type;
      switch (storage_type) {
        case '1':
          return "ssd";
        case '2':
          return "hdd";
        case '3':
          return "cd";
        case '4':
          return "dvd";   
        default:
          throw std::invalid_argument("Input is not a valid selection");
      } 
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }      
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

std::string get_storage_size() {
  char storage_size;
  while (true) {
    try {
      std::cout << "Select the storage size:\n1 for 128gb\n2 for 256gb\n"
                   "3 for 512gb\n4 for 1tb\n5 for 2tb\nselection: ";
      std::cin >> storage_size;
      switch (storage_size) {
        case '1':
          return "128gb";
        case '2':
          return "256gb";
        case '3':
          return "512gb";
        case '4':
          return "1tb";
        case '5':
          return "2tb";
        default:
          throw std::invalid_argument("input is not a valid selection");
      }
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

bool have_another_computer() {
  char input;
  while (true) {
    try {
      std::cout << "Would you like to enter another computer. Enter y/n: ";
      std::cin >> input;
      input = std::tolower(input);
      if (input == 'y') {
        return true;
      } else if(input == 'n') {
        return false;
      } else {
        throw std::invalid_argument("Input is not equal to y or n");
      }
    } catch (std::invalid_argument &e) {
      std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

int get_number_of_computers() {
  bool done = false;
  std::string number_of_computers;
  while (!done) {
    try {
      std::cout << "How many computers do you need to input: ";
      std::cin >> number_of_computers;
      if (number_of_computers < "0") {
        throw std::out_of_range("Number of computer must be greater then 0");
      }
      for (int i = 0; i < number_of_computers.size(); i++) {
        if (!std::isdigit(number_of_computers[i])) {
          throw std::invalid_argument("input is not a number");
        }
      }
      done = true;
    } catch (std::out_of_range &e) { 
      std::cerr << "Out of range: " << e.what() << "\n\n";
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
  }
  return std::stoi(number_of_computers);
}

int main() {
  std::vector<personal_computer> computer_list;
  int number_of_computers = get_number_of_computers();
  std::cout << '\n';
  while (number_of_computers--) {
    std::string manufacturer = get_manufacturer();
    std::cout << '\n';
    std::string form_factor = get_form_factor();
    std::cout << '\n';
    std::string serial_number = get_serial_number();
    std::cout << '\n';
    std::string processor = get_processor();
    std::cout << '\n';
    int ram = get_ram();
    std::cout << '\n';
    std::string storage_type = get_storage_type();
    std::cout << '\n';
    std::string storage_size = get_storage_size();
    std::cout << '\n';
    personal_computer computer(manufacturer, form_factor, serial_number, 
                               processor, ram, storage_type, storage_size);
    computer_list.push_back(computer);
    std::cout << "Computer number " << computer_list.size() << " info\n";
    std::cout << "----------------------\n";
    computer.print();     
    std::cout << std::endl;
    if (computer_list.size() == 1)
      std::cout << "** There is " << computer_list.size() << " computer in the list **\n\n";
    else 
      std::cout << "** There are " << computer_list.size() << " computers in the list **\n\n";
  }
  int index = 1;
  for (personal_computer& i: computer_list) {
    std::cout << "Computer " << index << '\n'; 
    std::cout << "-----------\n";
    std::cout << i.to_string(i) << std::endl;
    index++;
  }
}
