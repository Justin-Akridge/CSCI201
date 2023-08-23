#include <iostream>
#include <limits>
#include "StereoReceiver.h"

std::string getManufacturer() {
  std::string input;
  bool valid = false;
  do {
    std::cout << "Enter manufacturer: ";
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


std::string getModel() {
  std::string input;
  bool valid = false;
  do {
    std::cout << "Enter the model of the car: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an the model of car: ";
    }
  } while (!valid);
  return input;
}

std::string getSerial_number() {
  std::string input;
  bool valid = false;
  do {
    std::cout << "Enter the serial_number: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Serial number is invalid. ";
    }
  } while (!valid);
  return input;
}

int getWattage() {
  bool valid = false;
  do {
    int bass; 
    std::cout << "Enter bass: ";
    std::cin >> bass;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

int getNumber_of_channels() {
  bool valid = false;
  do {
    int bass; 
    std::cout << "Enter bass: ";
    std::cin >> bass;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

std::string getBand() {
  bool valid = false;
  do {
    int bass; 
    std::cout << "Enter bass: ";
    std::cin >> bass;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

double getFrequency() {
  bool valid = false;
  do {
    int bass; 
    std::cout << "Enter bass: ";
    std::cin >> bass;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

int getVolume() {
  bool valid = false;
  do {
    int volume;
    std::cout << "Enter volume: ";
    std::cin >> volume;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

bool getPower() {
  bool valid = false;
  do {
    bool input;
    std::cout << "Enter power: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

std::string getLights() {
  bool valid = false;
  do {
    std::string input;
    std::cout << "Enter color of lights: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
}

int getBass_booster() {
  //add in dial
  bool valid = false;
  do {
    int bass; 
    std::cout << "Enter bass: ";
    std::cin >> bass;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
  
}

int main() {
//  do {
//    std::cout << " 
//  } while (); 
}
