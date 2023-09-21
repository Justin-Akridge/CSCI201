#include <iostream>
#include "coffee.h"

CoffeeType::CoffeeType() {
  hot = true;
  caffeinated = true;
  roast_type = roast_type[0];
  strength = strength[0];
  creamer = "";
  sweetener = "";
}

CoffeeType::CoffeeType(bool init_hot, bool init_caffeinated, std::string init_roast_type, std::string init_strength, std::string init_creamer, bool init_sweetener) {
  hot = init_hot;
  caffeinated = init_caffeinated;
  assert(init_roast_type == "Light" || init_roast_type == "Medium" || init_roast_type == "Dark"
         init_roast_type == "French Roast" || init_roast_type == "Espresso");
  roast_type = init_roast_type;
  assert(strength == "light" || strength == "medium" || strength == "strong");
  strength = init_strength;
  creamer = init_creamer;
  
  sweetener = init_sweetener;
}

void CoffeeType::set_hot(bool new_value) {
  hot = new_value;
}

void set_caffeinated(bool new_value) {
  caffeinated = new_value;
}

void set_roast_type(std::string new_value) {
  roast_type = new_value;
} 

void set_strength(std::string new_value) {
  strength = new_value;
}

void set_sweetener(std::string new_value) {
  sweetener = new_value;
}

bool get_hot() const {
  return hot;
}

bool get_caffeinated() const {
  return caffeinated;
}

std::string get_roast_type() const {
  return roast_type;
}
  
std::string get_strength() const {
  return strength;
}
