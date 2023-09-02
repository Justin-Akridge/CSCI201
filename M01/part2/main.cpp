/*
 * Program name: stereo component
 * Author: Justin Akridge
 * Date last updated: 8/25/23
 * Purpose: Defines and implements a radio
 */
#include <iostream>
#include <exception>
#include <string>
#include <limits>
#include "StereoReceiver.h"

char see_all_settings();
int get_controls_input();
void set_control_settings(StereoReceiver& radio, int option);
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
  radio.setPower(true);
  std::cout << "Would you like to set any of the settings?\n";
  radio.print_controls();
  std::cout << '\n';
  int ans = get_controls_input();  
  set_control_settings(radio, ans);
  radio.setPower(false);
  std::cout << "GOODBYE!" << std::endl;
}

int get_controls_input() {
  int ans;
  do {
    try {
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
      if (ans != 0 && ans != 1 && ans != 2 && ans != 3 && 
          ans != 4 && ans != 5 && ans != 6 && ans != 9)
        throw std::out_of_range("Value is out of range");
    } catch (std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << '\n';
    }
  } while (ans != 0 && ans != 1 && ans != 2 && ans != 3 
           && ans != 4 && ans != 5 && ans != 6 && ans != 9);
  return ans;
}

char see_all_settings() {
  char input;
  while (true) {
    try {
      std::cin >> input;
      input = tolower(input);
      if (input != 'n' && input != 'y')
        throw std::invalid_argument("Value is not equal to yes or no");
      else
        break;
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  }  
  return input;
}

void set_control_settings(StereoReceiver& radio, int option) {
  do {
    try {
      if (option == 0) {
        radio.print_controls();
        std::cout << "Would you like to see all the settings? Y/N: ";
        char input;
        std::cin >> input;
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
        throw std::invalid_argument("Argument must be between 0-6 or 9 to exit");
      } 
    } catch (std::invalid_argument& e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  } while (option != 9);
} 

std::string get_string(std::string qtype) {
  std::string validate_input;
  bool valid_str = false;
  do {
    try {
      std::cout << "Enter " << qtype << ": ";
      std::cin >> validate_input;
      for (int i = 0; i < validate_input.size(); i++) {
        if (!isalpha(validate_input[i])) {
          throw std::invalid_argument("Value enter is not a string");
        }
      }
      valid_str = true;
    } catch(std::invalid_argument& e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    } 
  } while (!valid_str);
  return validate_input;
}

int get_int(std::string qtype) {
  bool valid_int = false;
  int ret;
  std::string validate_input; 
  do {
    try {
      std::cout << "Enter " << qtype << ": ";
      std::cin >> validate_input;
      for (int i = 0; i < validate_input.size(); i++) {
        if (!isdigit(validate_input[i])) {
          throw std::invalid_argument("Value must be an integer");
        }
      }
      ret = std::stoi(validate_input);
      valid_int = true;
    } catch (std::invalid_argument& e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  } while (!valid_int);
  return ret;
}

double get_double(std::string qtype) {
  bool valid_double = false;
  double ret;
  std::string input;
  do {
    try {
      std::cout << "Enter " << qtype << ": ";
      std::cin >> input;
      for (int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
          throw std::invalid_argument("Input is not a number");
        }
      }
      ret = std::stod(input);
      valid_double = true;
    } catch (std::invalid_argument& e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  } while (!valid_double);
  return ret;
}

bool get_bool(std::string qtype) {
  bool valid_bool = false;
  std::string input;
  do {
    try {
      std::cout << "Enter " << qtype << ": ";
      std::cin >> input;
      for (auto i : input)
        i = tolower(i);
      if (input == "true" || input == "false")
        valid_bool = true;
      else
        throw std::invalid_argument("Value is not equal to true or false");
    } catch(std::invalid_argument& e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  } while (!valid_bool);
  if (input == "true") 
    return true;
  else 
    return false;
}