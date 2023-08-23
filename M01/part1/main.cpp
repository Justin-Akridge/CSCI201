#include <iostream>
#include <limits>
#include <string>
#include "cube.h"

int getMeasurement(std::string side) {
  int input = -1;
  bool valid = false;
  do {
    if (side == "length")
      std::cout << "Enter the length of the cube: ";
    if (side == "height")
      std::cout << "Enter the height of the cube: ";
    if (side == "width")
      std::cout << "Enter the width of the cube: ";
    std::cin >> input;
    if (std::cin.good() && input > 0) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter an color: ";
    }
  } while (!valid);
  return input;
}

int main() {
  bool change = true;
  do {
    int length = getMeasurement("length");
    int height = getMeasurement("height");
    int width = getMeasurement("width");
    std::string color = getColor();
    cube new_cube(length, height, width, color); 
    new_cube.setLength(length);
    new_cube.setHeight(height);
    new_cube.setWidth(width);
    new_cube.setColor(color);
    std::cout << "Length = " << new_cube.getLength() << '\n'
              << "Width = " << new_cube.getWidth() << '\n'
              << "Height = " << new_cube.getHeight() << '\n'
              << "Color = " << new_cube.getColor() << '\n'
              << "Volume = " << new_cube.calculateVolume(length, height, width) << '\n';
    char ans = ' '; 
    while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
      std::cout << "Would you like to enter new measurements Y/N: "; 
      std::cin >> ans;
      if (ans == 'Y' || ans == 'y')
        break;
      else if (ans == 'N' || ans == 'n')
        change = false;
      else
        std::cout << "Invalid input" << std::endl;
    }

  } while (change);
}
