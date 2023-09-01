/*
 * Program name: stereo component
 * Author: Justin Akridge
 * Date last updated: 8/25/23
 * Purpose: Defines and implements a radio
 */
#include <iostream>
#include <exception>
#include <limits>
#include "StereoReceiver.h"

std::string get_string(std::string);
int get_int(std::string);
double get_double(std::string);
bool get_bool(std::string qtype);

int get_controls_input() {
  int ans;
  do {
    std::cout << "Press 0 display control settings\n";
    std::cout << "Press 1 to set the band\n";
    std::cout << "Press 2 to set the frequency\n";
    std::cout << "Press 3 to turn up/down the volume\n";
    std::cout << "Press 4 to to turn off/on the radio\n";
    std::cout << "Press 5 to turn the lights off/on\n";
    std::cout << "Press 6 to increase/decrease bass booster\n";
    std::cout << "Press 9 to quit\n";
    std::cout << '\n';
    std::cout << "Enter: ";
    std::cin >> ans;
  } while (ans != 0 && ans != 1 && ans != 2 && ans != 3 && ans != 4 && ans != 5 && ans != 6 && ans != 9);
    return ans;
}

char see_all_settings() {
  char input;
  do {
    std::cin >> input;
    input = tolower(input);
    if (input != 'n' && input != 'y') {
      std::cout << "Invalid input. Did you mean y/n? ";
      std::cin >> input;
    }
  } while (input != 'y' && input != 'n');
  return input;
}

void set_control_settings(StereoReceiver& radio, int option) {
  do {
    if (option == 0) {
      radio.print_controls();
      std::cout << "Would you like to see all the settings? Y/N: ";
      char input = see_all_settings();
      if (input == 'y') {
        radio.print();
      } else {
        break;
      }
    } else if (option == 1) {
        std::string band = get_string("AM or FM");
        radio.setBand(band);
    } else if (option == 2) {
        double frequency = get_double("frequency");
    } else if (option == 3) {
        int volume = get_int("volume");
    } else if (option == 4) {
        bool power = radio.getPower();
        if (power)
          radio.setPower(false);
        else
          radio.setPower(true);
    } else if (option == 5) {
        std::string lights = radio.getLights();
        if (lights == "on")
          radio.setLights("off");
        else if (lights == "off" || lights == "") 
          radio.setLights("on");
    } else if (option == 6) {
        int bass = get_int("bass volume");
    } else if (option == 9) {
        continue;
    } else {
        std::cout << "Invalid input\n";
    } 
  } while (option != 9);
} 

int main() {
  std::string manufacturer = get_string("manufacturer");
  std::string model = get_string("model");
  std::string serial_number = get_string("serial number");
  int wattage = get_int("wattage");
  int number_of_channels = get_int("number of channels");
  StereoReceiver radio(manufacturer, model, serial_number, wattage, number_of_channels);
  radio.print();
  radio.setPower(true);
  std::cout << "Would you like to set any of the settings?\n";
  radio.print_controls();
  std::cout << '\n';
  int ans = get_controls_input();  
  set_control_settings(radio, ans);
  radio.setPower(false);
  std::cout << "GOODBYE!" << std::endl;
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
