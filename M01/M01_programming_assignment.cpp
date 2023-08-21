#include <iostream>
#include <string>
#include "cube.h"

int getMeasurement() {
  int input = -1;
  bool valid = false;
  do {
    std::cout << "Enter the length of the cube: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      cin.ignore(numer_limits<streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an integer: ";
    }
  } while (!valid);
  return input;
}

std::string getColor() {
  std::string input = "";
  bool valid = false;
  do {
    std::cout << "Enter the color of the cube: ";
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      cin.ignore(numer_limits<streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an color: ";
    }
  } while (!valid);
  return input;
}

int main() {
  // TODO []: make this into a do while, validating input
  do {
    int length = getMeasurement();
    int height = getMeasurement();
    int width = getMeasurement();
    std::string color = getColor();
    cube new_cube(length, height, width, color); 
    new_cube.setLength(length);
    new_cube.setHeight(height);
    new_cube.setWidth(width);
    new_cube.setColor(color);
    bool change = true;
    char ans; 
    std::cout << "Would you like to enter new measurements Y/N: "; 
    std::cin >> ans;
    if (ans == 'Y' || ans == 'y') {
      continue;
    } else if (ans == 'N' || ans == 'n') {
      change = false;
    } else {
      std::cout << "Invalid input" << std::endl;
    } while (change)

  while (change) {
    int length = getMeasurement();
    int height = getMeasurement();
    int width = getMeasurement();
    std::string color = getColor();
  }
}
