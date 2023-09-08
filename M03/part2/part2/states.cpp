#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>

struct state {
  std::string state;
  std::string governor;
  std::string flower;
};

int main() {
  std::ifstream file("input.txt", std::ios::in);
  std::string str((std::istreambuf_iterator<std::string>(file)), (std::istreambuf_iterator<std::string>()));
  
  for (auto i : str) std::cout << i << std::endl;
  std::string state;
  std::string governor;
  std::string flower;
 // std::cin >> state >> governor >> flower;
 // std::cout << state << " " << governor << " " << flower << '\n';
}
