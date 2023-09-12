#include <iostream>
#include <vector>
#include <algorithm>
#include "Soldier.h"

bool validate_name(const std::string &input) {
  for (int i = 0; i < input.size(); i++) {
    if (!std::isalpha(input[i])) {
      return false;
    } 
  }
}

std::string get_name() {
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  return name;
}

bool is_valid_int(std::string &input) {
  for (int i = 0; i < input.size(); i++) {
    if (!std::isdigit(input[i])) {
      return false;
    }
  }
  return true;
}

bool is_correct_response(std::string &ranks, index) {
  std::cout << "
          std::cout << "Is " << ranks[index] << " the correct rank (y/n): "; 
}

std::string get_rank() {
  std::vector<std::string> ranks = {"E1", "E2", "E3", "E4A", "E4B", "E5", "E6", "E7A", "E7B", 
                                    "E8", "E9A", "E9B", "E9C", "W1", "W2", "W3", "W4", "W5", "O1", 
                                    "O2", "O3", "O4", "O5", "O6", "O7", "O8", "O9", "10a", "10b"};
  while (true) {
    try {
      std::cout << "\nSelect your rank:\n00 for E-1 private\n01 for E-2 private second class\n02 for E-3 private first class\n03 for E-4 specialist\n04 for E-4 corporal\n05 for E-5 sergeant\n06 for E-6 sergeant\n07 for E-7 staff sergeant\n08 for E-7 sergeant first class\n09 for E-8 master sergeant\n10 for E-9 sergeant major\n11 for E-9 command sergeant major\n12 for E-9 Sergeant major of the army\n13 for W-1 Warrant officer 1\n14 for W-2 Chief warrant officer 2\n15 for W-3 chief warrant officer 3\n16 for W-4 chief warrant officer 4\n17 for W-5 chief warrant offcier 5\n18 for O-1 second lieutenant\n19 for O-2 first lieutenant\n17 for O-3 captain\n18 for O-4 major\n19 for O-5 lieutenant coloniel\n20 for O-6 colonel\n21 for O-7 brigadier general\n22 for O-8 major general\n23 for O-9 lieutenant general\n24 for O-10 general\n25 for O-10 general of the army\nselection: ";
      std::string input;
      std::cin >> input;
      if (is_valid_int(input)) {
        int index = std::stoi(input);
        if (index >= 0 && index <= 25) {
          if (is_correct_response(ranks, index) {
              return ranks[index];
          } 
        } else if (index < 0) {
          throw std::out_of_range("input must be greater then or equal to 0.");
        } else {
          throw std::out_of_range("input must be less then or equal to 25.");
      } else {
          throw std::invalid_argument("input is not a valid selection.");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    } catch (std::out_of_range &e) {
      std::cerr << "Out of range: " << e.what() << "\n\n";
    }
  }
}

int main() {
  //std::vector<Soldier> soldiers;

  //std::string name;
  //std::string rank;
  //std::string classification;
  //double pay;
  get_rank();
}
