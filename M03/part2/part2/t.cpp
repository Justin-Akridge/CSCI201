#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>

int main() {
  std::ifstream file("input.txt", std::ios::in);
  std::string str((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
  std::cout << str << "\n";
}
