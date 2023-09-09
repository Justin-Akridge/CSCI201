/*
 * Justin Akridge
 * 09/09/2023
 * CSCI201
 * This program collects a stream of data in the form of (state, governor, flower) and stores
 * each states info into a map. The user can look up the values by the states initials.
 */
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

void parse_string(std::string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-') {
      s[i] = ' ';
    }
  }
}

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
    bool done = false;
    while(!done) {
      state new_state;
      file >> new_state.state >> new_state.governor >> new_state.flower;
      parse_string(new_state.state);
      parse_string(new_state.governor);
      parse_string(new_state.flower);
      states[state_abbreviation[index]] = new_state;
      index++;
      if (index == 50)
        done = true;
    }
  }
  file.close();
  
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter a two letter abbreviation of a state or -1 to quit: ";
      std::string state_selection;
      std::cin >> state_selection;
      std::cout << '\n';
      if (state_selection == "-1") {
        done = true;
        continue;
      }
      for (int i = 0; i < state_selection.size(); i++) {
        state_selection[i] = std::toupper(state_selection[i]);
      }
      bool is_valid_state = false;
      for (itr = states.begin(); itr != states.end(); itr++) {
        if (state_selection == itr->first) {
          is_valid_state = true;
          std::cout << "State: " << itr->second.state << '\n';
          std::cout << "Governor: " << itr->second.governor << '\n';
          std::cout << "Flower: " << itr->second.flower << "\n\n";
        }      
      }
      if(!is_valid_state) {
        throw std::invalid_argument("{ " + state_selection + " } abbreviation is not a valid state.\n\n");
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what();
    }
  }
}
