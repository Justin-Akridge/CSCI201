#include <iostream>
#include <array>
#include <limits>

std::array<int, 16> get_data() {
  std::array<int, 16> arr;
  for (int i = 0; i < arr.size(); i++) {
    std::cout << "Enter week " << i + 1 << " score: ";
    std::cin >> arr[i];
  }
  return arr;
}

int high_score(std::array<int, 16> &arr) {
  int high_score = INT_MIN;
  for (int &i : arr) {
    if (i > high_score) {
      high_score = i;
    }
  }
  return high_score;
}

int lowest_score(std::array<int, 16> &arr) {
  int lowest_score = INT_MAX;
  for (int &i : arr) {
    if (i < lowest_score) {
      lowest_score = i;
    }
  }
  return lowest_score;
}

int main() {
  std::array<int, 16> a = get_data();
  for (auto &i : a) {
    std::cout << i << std::endl;
  }
}
