#include "Soldier.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <cctype>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>

bool validate_name(const std::string &input) {
  for (int i = 0; i < input.size(); i++) {
    if (!std::isalpha(input[i]) && !std::isspace(input[i])) {
      return false;
    } 
  }
  return true;
}

std::string get_name() {
  std::string name;
  while (true) {
    try {
      std::string first_name;
      std::cout << "Enter your first name: ";
      std::cin >> first_name;
      first_name[0] = std::toupper(first_name[0]);
      std::string last_name;
      std::cout << "Enter you last name: ";
      std::cin >> last_name;
      last_name[0] = std::toupper(last_name[0]);
      std::string full_name = first_name + " " + last_name;
      if (validate_name(full_name)) {
        return full_name;
      } else {
        throw std::invalid_argument("Name must contain characters a-z.");
      }
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << '\n';
    }
  }
}

bool is_valid_int(std::string &input) {
  for (int i = 0; i < input.size(); i++) {
    if (!std::isdigit(input[i])) {
      return false;
    }
  }
  return true;
}

bool is_correct_rank(std::string &ranks, int index) {
  char input;
  while (true) {
    try {
      std::cout << "Is " << ranks[index] << " the correct rank (y/n): "; 
      std::cin >> input;
      input = std::tolower(input);
      if (input == 'y') {
        return true;
      } else if (input == 'n') {
        return false;
      } else {
        std::invalid_argument("input must be y/n.");
      }
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
  }
}

std::string get_rank_classification(int index) {
  assert (index >= 0 && index <= 29);
  std::vector<std::string> ranks = {"E1", "E2", "E3", "E4A", "E4B", "E5", "E6", 
                                    "E7A", "E7B", "E8", "E9A", "E9B", "E9C", 
                                    "W1", "W2", "W3", "W4", "W5", "O1", "O2", 
                                    "O3", "O4", "O5", "O6", "O7", "O8", "O9", 
                                    "O10a", "O10b"};
  std::string classification = ranks[index];
  if (classification[0] == 'E') {
    return "Enlisted";
  } else if (classification[0] == 'W') {
    return "Warrant";
  } else {
    return "Officer";
  }
}

int get_rank_index() {
  std::string input;
  while (true) {
    try {
      std::cout << "Select your rank:\n00 for E-1 private\n"
                    "01 for E-2 private second class\n02 for E-3 private first class\n"
                    "03 for E-4 specialist\n04 for E-4 corporal\n05 for E-5 sergeant\n"
                    "06 for E-6 sergeant\n07 for E-7 staff sergeant\n"
                    "08 for E-7 sergeant first class\n09 for E-8 master sergeant\n"
                    "10 for E-9 sergeant major\n11 for E-9 command sergeant major\n"
                    "12 for E-9 Sergeant major of the army\n13 for W-1 Warrant officer 1\n"
                    "14 for W-2 Chief warrant officer 2\n15 for W-3 chief warrant officer 3\n"
                    "16 for W-4 chief warrant officer 4\n17 for W-5 chief warrant offcier 5\n"
                    "18 for O-1 second lieutenant\n19 for O-2 first lieutenant\n"
                    "20 for O-3 captain\n18 for O-4 major\n21 for O-5 lieutenant coloniel\n"
                    "22 for O-6 colonel\n23 for O-7 brigadier general\n"
                    "24 for O-8 major general\n25 for O-9 lieutenant general\n"
                    "26 for O-10 general\n27 for O-10 general of the army\nselection: ";
      std::cin >> input;
      int index;
      if (is_valid_int(input)) {
        index = std::stoi(input);
      } else {
        throw std::invalid_argument("input must be a number.");
      }
      if (index >= 0 && index <= 28) {
        return index;
      } else if (index < 0) {
        throw std::out_of_range("input must be greater then or equal to 0.");
      } else if (index > 28){
        throw std::out_of_range("input must be less then or equal to 28.");
      } else {
        throw std::invalid_argument("input is not a valid number.");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    } catch (std::out_of_range &e) {
      std::cerr << "Out of range: " << e.what() << "\n\n";
    } catch (...) {
      std::cerr << "Invalid argument: you must provide the correct input.\n\n";
    }
  }
}

std::string get_classification(int index) {
  std::vector<std::string> classifications = {"private","private second class", "private first class", 
                                              "specialist", "corporal", "sergeant",
                                              "sergeant", "staff sergeant",
                                              "sergeant first class", "master sergeant",
                                              "sergeant major", "command sergeant major",
                                              "Sergeant major of the army", "Warrant officer 1",
                                              "Chief warrant officer 2", "chief warrant officer 3",
                                              "chief warrant officer 4", "chief warrant offcier 5",
                                              "second lieutenant", "first lieutenant",
                                              "captain", "major", "lieutenant coloniel",
                                              "colonel", "brigadier general",
                                              "major general", "lieutenant general",
                                              "general", "general of the army"};
  return classifications[index];
}

int main() {
  std::vector<std::string> pay_scale;
  std::ifstream pay_scale_file ("input.txt");
  if(pay_scale_file.is_open()) {
    std::string pay_input;
    while (pay_scale_file.good()) {
      std::getline(pay_scale_file, pay_input);
      pay_scale.push_back(pay_input);
    }
  } else {
    std::cout << "Unable to open file.\n";
  }
  std::vector<Soldier> soldiers;
  for (int i = 0; i < 7; i++) {
    std::string name = get_name();
    int rank_index = get_rank_index();
    std::string classification = get_rank_classification(rank_index);
    std::string rank = get_classification(rank_index);
    std::string pay = pay_scale[rank_index];
    Soldier new_soldier(name, rank, classification, pay);
    soldiers.push_back(new_soldier);
    std::string print = new_soldier.to_string();
    std::cout << print << std::endl;
  }
}
