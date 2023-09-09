/*
 * Justin Akridge
 * 09/09/2023
 * CSCI201
 * This problem calculates the average grade and lowest/highest grade over 16 different tests
 * grade calculator
 */
#include <iostream>
#include <array>
#include <climits>
#include <limits>
#include <string>
#include <cctype>

bool is_valid_int(std::string s) {
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 && s[i] == '-') {
      continue;
    }
    if (!std::isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

std::array<int, 16> get_data() {
  std::array<int, 16> arr;
  for (int i = 0; i < arr.size(); i++) {
    bool done = false;
    while (!done) {
      try {
        std::cout << "Module " << i + 1 << " score: ";
        std::string num;
        std::cin >> num;
        if (is_valid_int(num)) {
          int value = std::stoi(num);
          if (value >= 0 && value <= 15) {
            done = true;
            arr[i] = value;
          } else {
            throw std::invalid_argument("{ " + num + " } is not a valid score."
                                        " Score must be between 0 and 15.");
          }
        } else {
          throw std::invalid_argument("{ " + num + " } is not a number.");
        }
      } catch (std::invalid_argument &e) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid argument: " << e.what() << '\n';
      }
    }
  }
  return arr;
}

int get_average_score(std::array<int, 16> &arr) {
  int total = 0;
  for (int &i : arr) {
    total += i;
  }
  return total / arr.size();
}

int get_high_score(std::array<int, 16> &arr) {
  int high_score = INT_MIN;
  int index = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > high_score) {
      high_score = arr[i];
      index = i;
    }
  }
  return index;
}

int get_lowest_score(std::array<int, 16> &arr) {
  int lowest_score = INT_MAX;
  int index = -1;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] < lowest_score) {
      lowest_score = arr[i];
      index = i;
    }
  }
  return index;
}

int main() {
  std::array<int, 16> scores = get_data();
  int pos_of_low = get_lowest_score(scores);
  int pos_of_high = get_high_score(scores);
  int average = get_average_score(scores);
  for (int i = 0; i < scores.size(); i++) {
    std::cout << "Module " << i + 1 << ": " << scores[i] << "\n\n";
  }
  std::cout << "Average grade: " << average << '\n';
  std::cout << "Your lowest score was in module " << pos_of_low + 1
            << " with " << scores.at(pos_of_low) << '\n';
  std::cout << "Your highest score was in module " << pos_of_high + 1
            << " with " << scores.at(pos_of_high) << '\n';

}
