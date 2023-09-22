#include <iostream>
#include <cassert>

class BeverageType {
public:
  BeverageType() {
    name = "";
    description = "";
    serving_size = 0;
    calories = 0;
    price = 0.0;
  }
  BeverageType(std::string init_name, std::string init_description, 
                            int init_serving_size, int init_calories, 
                            double init_price) {
     name = init_name;
     } else {
       throw std::invalid_argument("Name must contain characters from a-z");
     } 
     if (is_valid_string(init_description)) {
       description = init_description;
     } else {
       throw std::invalid_argument("Description must contain characters from a-z");
     }
     if (in_valid_int(init_serving_size)) {
       serving_size = init_serving_size;
     } else {
       throw std::invalid_argument("Input is not a number");
     }
     if (is_valid_int(init_calories)) {
       calories = init_calories;
     } else {
       throw std::invalid_argument("Input is not a number");
     }
     if (init_price > 0) {
       price = init_price;
     } else {
       throw std::invalid_argument("input must be greater then 0");
     }
   } catch (std::invalid_argument &e) {
     std::cerr << "Invalid argument: " << e.what() << std::endl;
   } catch (...) {
     std::cerr << "Error, something went wrong\n";
   }
  }
  std::string to_string() {
    std::string ret = "Name: " + name + "\ndescription" + description + 
                      "\nServing size: " + serving_size + "\nCalories: " + calories + '\n';
  }
private:
  std::string name;
  std::string description;
  int serving_size;
  int calories;
  double price;
};

class CoffeeType : public BeverageType {
public:
  CoffeeType() {
    hot = true;
    caffeinated = true;
    roast_type = roast_type[0];
    strength = strength[0];
    creamer = "";
    sweetener = "";
  }
  CoffeeType(bool init_hot, bool init_caffeinated, std::string init_roast_type, 
             std::string init_strength, std::string init_creamer, bool init_sweetener) {
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
