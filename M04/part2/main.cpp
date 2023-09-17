/*
 * Justin Akridge
 * Program name: Shooter game
 * 09/15/2023
 * Purpose: Program shoots nerf guns and ...
 */
#include <iostream>
#include <vector>
#include "nerf-gun.h"

std::string get_model() {
  while (true) {
    try {
      std::string model = "";
      std::cout << "Enter the model of the nerf gun: ";
      std::cin >> model;
      for (auto i : model) {
        if (!std::isalpha(i)) {
          throw std::invalid_argument("Model must contain characters from a-z");
        }
      }
      return model;
    } catch (std::invalid_argument &e) {
      std::cerr << "invalid argument: " << e.what() << '\n';
    }
  }
}

int get_range() {
  std::string range;
  while (true) {
    try {
      std::cout << "Enter the range of the gun: ";
      std::cin >> range;
      for (int i = 0; i < range.size(); i++) {
        if (!std::isdigit(range[i])) {
          throw std::invalid_argument("range must be a number.");
        }
      }
      int input = std::stoi(range);
      return input;
    } catch (std::invalid_argument &e) {
      std::cerr << "invalid argument: " << e.what() << std::endl;
    }
  }
}

int get_capacity() {
  std::string capacity;
  while (true) {
    try {
      std::cout << "Enter the capacity of the gun: ";
      std::cin >> capacity;
      for (auto i : capacity) {
        if (!std::isdigit(i)) {
          throw std::invalid_argument("Input must be a number.");
        }
      }
      int capacity_input = std::stoi(capacity);
      return capacity_input;
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  }
}

int main() {
  std::vector<Nerf_gun> nerf_guns;
  for (int i = 0; i < 2; i++) {
    std::cout << "Gun " << i << "\n";
    std::string model = get_model();
    int range = get_range();
    int capacity = get_capacity();
    std::cout << '\n';
    Nerf_gun new_gun(model, range, capacity);
    std::cout << new_gun;
    nerf_guns.push_back(new_gun);
  }
  std::string model;
  int range;
  int capacity;
}
