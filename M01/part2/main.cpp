#include <iostream>
#include <limits>
#include "StereoReceiver.h"

std::string get_string(std::string);
int get_int(std::string);
double get_double(std::string);
bool get_bool(std::string qtype);

int main() {
  std::string manufacturer = get_string("manufacturer");
  std::string model = get_string("model");
  std::string serial_number = get_string("serial number");
  int wattage = get_int("wattage");
  int number_of_channels = get_int("number of channels");
  StereoReceiver radio(manufacturer, model, serial_number, wattage, number_of_channels);
  radio.print();
  int power = radio.setPower(true);
  if (power) 
    std::cout << "Error\n";
  std::cout << "Would you like to set any of the settings?\n";
  radio.print_settings();
  std::cout << '\n';
  int ans;
  do {
    std::cout << "Press 1 to set the band\n";
    std::cout << "Press 2 to set the frequency\n";
    std::cout << "Press 3 to turn up/down the volume\n";
    std::cout << "Press 4 to to turn off the radio\n";
    std::cout << "Press 5 to turn the lights off/on\n";
    std::cout << "Press 6 to increase/decrease bass booster\n";
    std::cout << "Press 9 to quit\n";
    std::cin >> ans;
    switch(ans) {
      case 1:
        std::string band = get_string("band");
        radio.setBand(band);
        break;
      case 2:
        double frequency = get_double("frequency");
        radio.setFrequency(frequency);
        break;
      case 3:
        int volume = getVolume("volume")
    }
  } while (ans != 9);
}

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