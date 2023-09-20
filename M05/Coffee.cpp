#include <iostream>
#include "coffee.h"

enum strength {"light", "medium", "strong"};
enum roast_type {"Light", "Medium", "Dark", "French Roast", "Espresso"};
CoffeeType::CoffeeType() {
  hot = true;
  caffeinated = true;
  roast_type = roast_type[0];
  strength = strength[0];
  creamer = "";
  sweetener = "";
}

CoffeeType::CoffeeType(bool init_hot, bool init_caffeinated, std::string roart, enum, std::string, std::string) {
  
}

void set_hot(bool);
void set_caffeinated(bool);
void set_roast_type(std::string);
void set_strength(std::string);
void set_sweetener(std::string);
bool get_hot() const;
bool get_caffeinated() const;
std::string get_roast_type() const;
std::string get_strength() const;

bool hot;
bool caffeinated
std::string roast_type 
//(Light, Medium, Dark, French Roast, Espresso)
enum strength;
std::string creamer;
std::string sweetener;
