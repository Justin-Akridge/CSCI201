#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

struct state {
  std::string state;
  std::string governor;
  std::string flower;
};

int main() {
  std::vector<std::string> state_abbreviation = {"AL", "AK", "AZ", "AR", "CA", 
                              "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", 
                              "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", 
                              "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", 
                              "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR", 
                              "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", 
                              "VA", "WA", "WV", "WI", "WY"};
  std::unordered_map<std::string, state> states;
  std::unordered_map<std::string, state>::iterator itr;
  std::ifstream file("input.txt");
  if (file.is_open()) {
    std::string line;
    int index = 0;
    while(file.good() && !file.eof()) {
      state new_state;
      file >> new_state.state >> new_state.governor >> new_state.flower;
      std::cout << new_state.state << new_state.governor << new_state.flower << std::endl;
      states[state_abbreviation[index]] = new_state;
      index++;
    }
  }
  file.close();
  
  bool done = false;
  while (!done) {
    std::cout << "Enter a two letter abbreviation of a state: ";
    std::string state_selection;
    std::cin >> state_selection;
    std::cout << '\n';
    for (int i = 0; i < state_selection.size(); i++) {
      state_selection[i] = std::toupper(state_selection[i]);
    }
    for (itr = states.begin(); itr != states.end(); itr++) {
      if (state_selection == itr->first) {
        std::cout << "State: " << itr->second.state << '\n';
        std::cout << "Governor: " << itr->second.governor << '\n';
        std::cout << "Flower: " << itr->second.flower << "\n\n";
      }
    }
  }
}
