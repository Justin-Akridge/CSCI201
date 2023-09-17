/*
 * Justin Akridge
 * Program name: Shooter game
 * 09/15/2023
 * Purpose: Program shoots nerf guns and ...
 */
#include <iostream>
#include <vector>

std::string get_model() {
  while (true) {
    std::string model = "";
    std::cout << "Enter the model of the nerf gun: ";
    std::cin >> model;
    for (true) {
      if (!std::isalpha(model[i])) {
        throw std::invalid_argument("Model must contain characters from a-z");
      }
    }
    return model;
  } catch (std::invalid argument &e) {
    std::cerr << "invalid argument: " << e.what() << '\n';
  }
}

int get_range() {
  std::string range;
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter the range of the gun: ";
      std::cin >> range;
      for (int i = 0; i < range.size(); i++) {
        if (!std::isalpha(range[i])) {
          throw std::invalid_argument("range must be a number.");
        }
      }
      int input = std::stoi(range);
      done = true;
    } catch (std::invalid_argument &e) {
      std::cerr << "invalid argument: " << e.what() << std::endl;
    }
  }
  return input;
}

int main() {
  std::vector<Nerf_gun> nerf_guns;
  for (int i = 0; i < 2; i++) {
    std::string model = get_model();
        
    Nerf_gun new_gun(std::string, int, int);
    nerf_guns.push_back(new_gun);
  }
  std::string model;
  int range;
  int capacity;
  }
}
