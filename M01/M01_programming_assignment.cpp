#include "cube.h"

int main() {
  //validate input
  int length;
  std::cout << "Enter the length of the cube: ";
  if (std::cin >> length);
  int height;
  std::cout << "Enter the length of the cube: ";
  std::cin >> height;

  int width;
  std::cout << "Enter the width of the cube: ";
  std::cin >> width;

  std::string color;
  std::cout << "Enter the color of the cube: ";
  std::cin >> color;

  cube new_cube(length, height, width, color); 
}
