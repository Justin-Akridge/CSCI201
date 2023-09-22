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
  void to_string() {
    std::cout << "Name: " << name << "\ndescription" << description
              << "\nServing size: " << std::to_string(serving_size) << "\nCalories: "
              << std::to_string(calories) << '\n';
  }

  void set_name(std::string new_name) {
    name = new_name;
  }

  void set_description(std::string new_description) {
    description = new_description;
  }

  void set_serving_size(int new_serving_size) {
    serving_size = new_serving_size;
  }

  void set_calories(int new_calories) {
    calories = new_calories;
  }

  void set_price(double new_price) {
    price = new_price;
  }

  std::string get_name() const {
    return name;
  }

  std::string get_description() const {
    return description;
  }

  int get_serving_size() const {
    return serving_size;
  }

  int get_calories() const {
    return calories;
  }

  double get_price() const {
    return price;
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
             int init_serving_size, int init_calories, double init_price, bool init_hot, 
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

  void set_hot(bool new_hot) {
    hot = new_hot;
  }

  void set_caffeinated(bool new_caffeinated) {
    caffeinated = new_caffeinated;
  }

  void set_roast_type(std::string new_roast_type) {
    roast_type = new_roast_type;
  }

  void set_strength(std::string new_strength) {
    strength = new_strength;
  }
  
  void set_creamer(std::string new_creamer) {
    creamer = new_creamer;
  }

  void set_sweetener(bool new_sweetener) {
    sweetener = new_sweetener;
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

  std::string get_creamer() const {
    return creamer;
  }

  bool get_sweetener() const {
    return sweetener;
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
  TeaType() {
    type = "";
    hot = false;
    creamer = "";
    sweetener = "";
    lemon = true;

  }
  TeaType(std::string init_name, std::string init_description, int init_serving_size, int init_calories, 
          double init_price, std::string init_type, bool init_hot, std::string init_creamer, 
          std::string init_sweetener, bool init_lemon) :
          BeverageType(init_name, init_description, init_serving_size,
                       init_calories, init_price){
    type = init_type;
    hot = init_hot;
    creamer = init_creamer;
    sweetener = init_sweetener;
    lemon = init_lemon;
  }
  void to_string() {
    if (hot) {
      if (lemon) {
        std::cout << "type: " << type << "\nhot/cold: " << "hot\n" << "creamer: "
                  << creamer << "\nsweetener: " << sweetener << "lemon: " << "yes\n"; 
      } else {
        std::cout << "type: " << type << "\nhot/cold: " << "hot\n" << "creamer: "
                  << creamer << "\nsweetener: " << sweetener << "lemon: " << "no\n";
      }

    } else {
      if (lemon) {
        std::cout << "type: " << type << "\nhot/cold: " << "cold\n" << "creamer: "
                  << creamer << "\nsweetener: " << sweetener << "lemon: " << "yes\n"; 
      } else {
        std::cout << "type: " << type << "\nhot/cold: " << "cold\n" << "creamer: "
                  << creamer << "\nsweetener: " << sweetener << "lemon: " << "no\n"; 
      }
    }
  }

  void set_type(std::string new_type) {
    type = new_type;
  }

  void set_hot(bool new_hot) {
    hot = new_hot;
  }
  
  void set_creamer(std::string new_creamer) {
    creamer = new_creamer;
  }

  void set_sweetener(std::string new_sweetener) {
    sweetener = new_sweetener;
  }

  void set_lemon(bool new_lemon) {
    lemon = new_lemon;
  }

  std::string get_type() const {
    return type;
  }

  bool get_hot() const {
    return hot;
  }

  std::string get_creamer() const {
    return creamer;
  }

  std::string get_sweetener() const {
    return sweetener;
  }

  bool get_lemon() const {
    return lemon;
  }

private:
  std::string type;
  bool hot;
  std::string creamer;
  std::string sweetener;
  bool lemon;
};

class SodaType : public BeverageType {
public:
  SodaType() {
    brand = "";
    type = "";
    diet = false;
  }
  SodaType(std::string init_name, std::string init_description, int init_serving_size, 
           int init_calories, double init_price, std::string init_brand, std::string init_type, 
           bool init_diet) :
           BeverageType(init_name, init_description, init_serving_size,
                        init_calories, init_price) {
    brand = init_brand;
    type = init_type;
    diet = init_diet;
  }
  void to_string() {
    std::cout << "Brand: " << brand << "\nType: " << type << "\nDiet: " << diet << '\n';
  }

  void set_brand(std::string new_brand) {
    brand = new_brand;
  }
  
  void set_type(std::string new_type) {
    type = new_type;
  }

  void set_diet(bool new_diet) {
    diet = new_diet;
  }
  
  std::string get_brand() const {
    return brand;
  }

  std::string get_type() const {
    return type;
  }

  bool get_diet() const {
    return diet;
  }

private:
  std::string brand;
  std::string type;
  bool diet;
};

class EnergyDrinkType : public BeverageType {
public:
  EnergyDrinkType() {
    brand = "";
    stimulant = "caffeine";
    sweetener = true; 
  }

  EnergyDrinkType(std::string init_name, std::string init_description, 
                  int init_serving_size, int init_calories, double init_price, 
                  std::string init_brand, std::string init_stimulant, bool init_sweetener) :
     BeverageType(init_name, init_description, init_serving_size, init_calories, 
                  init_price) {
    brand = init_brand;
    stimulant = init_stimulant;
    sweetener = init_sweetener;
  }

  void to_string() {
    std::cout << "Brand: " << brand << "\nStimulant: " << stimulant << "\nSweetener: "
              << sweetener << '\n';
  }
  
  void set_brand(std::string new_brand) {
    brand = new_brand;
  }
  
  void set_stimulant(std::string new_stimulant) {
    stimulant = new_stimulant;
  }

  void set_sweetener(bool new_sweetener) {
    sweetener = new_sweetener;
  }

  std::string get_brand() const {
    return brand;
  }
  
  std::string get_stimulant() const {
    return stimulant;
  }

  bool get_sweetener() const {
    return sweetener;
  }

private:
  std::string brand;
  std::string stimulant;
  bool sweetener;
};

int main() {
  CoffeeType c1("mocha", "this is nice", 5, 5, 5, true, false, "4345", "light", "asdfb", true);
  std::cout << c1.get_hot() << std::endl;
  std::cout << "OKAY\n";
}


