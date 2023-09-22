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
  bool is_valid_string(std::string &s) {
    for (int i = 0; i < s.size(); i++) {
      if (!std::isalpha(s[i]) && !std::isspace(s[i])) {
        return false;
      }
    }
    return true;
  }
  BeverageType(std::string init_name, std::string init_description, 
               int init_serving_size, int init_calories, double init_price) {
    try {
      if (is_valid_string(init_name)) {
        name = init_name;
      } else {
        throw std::invalid_argument("Name must contain characters from a-z");
      } 
      if (is_valid_string(init_description)) {
        description = init_description;
      } else {
        throw std::invalid_argument("Description must contain characters from a-z");
      }
      serving_size = init_serving_size;
      calories = init_calories;
      assert(init_price > 0);
      price = init_price;
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
  }
  std::string to_string() {
    std::string ret = "Name: " + name + "\ndescription" + description +
                      "\nServing size: " + std::to_string(serving_size) + "\nCalories: " + 
                      std::to_string(calories) + '\n';
    return ret;
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
    roast_type = "French Roast";
    strength = "light";
    creamer = "";
    sweetener = false;
  }
  CoffeeType(std::string init_name, std::string init_description, 
             int init_serving_size, int init_calories, int init_price, bool init_hot, 
             bool init_caffeinated, std::string init_roast_type, 
             std::string init_strength, std::string init_creamer, bool init_sweetener) :
             BeverageType(init_name, init_description, init_serving_size,
                         init_calories, init_price){

    hot = init_hot;
    caffeinated = init_caffeinated;
    roast_type = init_roast_type;
    assert(init_strength == "light" || init_strength == "medium" || init_strength == "strong");
    strength = init_strength;
    creamer = init_creamer;
    sweetener = init_sweetener;
  }
  bool get_hot() {
    return hot;
  }
private:
  bool hot;
  bool caffeinated;
  std::string roast_type;
  std::string strength;
  std::string creamer;
  bool sweetener;
};

class TeaType : public BeverageType {
public:
  TeaType();
  TeaType(init_name, init_description, init_serving_size, init_calories, 
          init_price, std::string init_type, bool init_hot, std::string init_creamer, 
          std::string init_sweetener, bool init_lemon) :
          BeverageType(init_name, init_description, init_serving_size,
                       init_calories, init_price){
    //maybe add validation
    type = init_type;
    hot = init_hot;
    creamer = init_creamer;
    sweetener = init_sweetener;
    lemon = init_lemon;
  }
  std::string to_string() {
    std::cout << "type: " << type << "\nhot/cold: " << hot ? "hot\n" : "cold\n" << "Creamer: ";
              << creamer << "\nsweetener: " << sweetener << "Lemon: " << lemon ? "yes" : "no"; 
  }
private:
  std::string type;
  bool hot;
  std::string creamer;
  std::string sweetener;
  bool lemon;
};

TeaType::TeaType() {
  type = "";
  hot = false;
  creamer = "";
  sweetener = "";
  lemon = false;
}

class SodaType {
public:
  SodaType() {
    brand = "";
    type = "";
    diet = false;
  }
  SodaType(std::string init_brand, std::string init_type, bool init_diet) :
           BeverageType(init_name, init_description, init_serving_size,
                        init_calories, init_price) {
    brand = init_brand;
    type = init_type;
    diet = init_diet;
  }
  void to_string(
private:
  std::string brand;
  std::string type;
  bool diet;
};

int main() {
  CoffeeType c1("mocha", "this is nice", 5, 5, 5, true, false, "4345", "light", "asdfb", true);
  std::cout << c1.get_hot() << std::endl;
  std::cout << "OKAY\n";
}


