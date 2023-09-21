#ifndef COFFEE_H
#define COFFEE_H
#include "Beverage.h"

class CoffeeType : public BeverageType {
public:
  CoffeeType();
  CoffeeType(bool, bool, std::string, enum, std::string, std::string);
  void set_hot(bool);
  void set_caffeinated(bool);
  void set_roast_type(std::string);
  void set_strength(std::string);
  void set_sweetener(std::string);
  bool get_hot() const;
  bool get_caffeinated() const;
  std::string get_roast_type() const;
  std::string get_strength() const;
  bool get_sweetener() const;
private:
  bool hot;
  bool caffeinated
  std::string roast_type 
  std::string strength;
  std::string creamer;
  std::string sweetener;
};
#endif
