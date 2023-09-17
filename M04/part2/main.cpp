/*
 * Justin Akridge
 * Program name: Shooter game
 * 09/15/2023
 * Purpose: Program shoots nerf guns and ...
 */
#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>
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
  //display which gun has the most ammo
  std::srand(time(nullptr));
  for (int i = 0; i < 100; i++) {
    std::cout << "LOOP # " << i << '\n';
    int index_of_gun_with_most_ammo = 0; 
    for (int i = 1; i < nerf_guns.size(); i++) {
      if (nerf_guns[index_of_gun_with_most_ammo] < nerf_guns[i]) {
        index_of_gun_with_most_ammo = i;
      }
    }
    std::cout << "Player with the most ammo: " << nerf_guns[index_of_gun_with_most_ammo] << '\n';
    int random_gun = std::rand() % nerf_guns.size();
    --nerf_guns[random_gun];
    if (nerf_guns[random_gun].get_dart_count() == 0) {
      int darts;
      std::cout << "Enter number of darts: ";
      std::cin >> darts;
      nerf_guns[random_gun] += darts;
    }
    std::cout << "STATUS OF NERF GUN AFTER FIRED\n" << nerf_guns[random_gun] << std::endl;
  }
}
