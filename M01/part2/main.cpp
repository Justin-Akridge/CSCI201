#include <iostream>
#include <limits>
#include "StereoReceiver.h"

std::string get_string(std::string qtype) {
  std::string input;
  bool valid = false;
  do {
    std::cout << "Enter " << qtype << ": ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an string: ";
    }
  } while (!valid);
  return input;
}

int get_int(std::string qtype) {
  bool valid = false;
  int input; 
  do {
    std::cout << "Enter " << qtype << ": ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
  return input;
}

double get_double(std::string qtype) {
  bool valid = false;
  double input;
  do {
    std::cout << "Enter " << qtype << ": ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an double: ";
    }
  } while (!valid);
  return input;
}

bool get_bool(std::string qtype) {
  bool valid = false;
  bool input;
  do {
    std::cout << "Enter " << qtype << ": ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
  return input;
}

int main() {
  std::string manufacturer = get_string("manufacturer");
  std::string model = get_string("model");
  std::string serial_number = get_string("serial number");
  int wattage = get_int("wattage");
  int number_of_channels = get_int("number of channels");
  StereoReceiver radio(manufacturer, model, serial_number, wattage, number_of_channels);
  radio.print();
}