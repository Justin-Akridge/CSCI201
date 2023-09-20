#include "BeverageType.h"
#include <iostream>
#include <cassert>

BeverageType::BeverageType() {
  name = "";
  description = "";
  serving_size = 0;
  calories = 0;
  price = 0.0;
}

BerverageType::BeverageType(std::string init_name, std::string init_description, 
                            int init_serving_size, int init_calories, 
                            double init_price) {
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

void BeverageType::set_price(double init_price) {
  assert(init_price > 0);
  price = init_price;
}

std::string BeverageType::get_name() const {
  return name;
}
  
std::string BeverageType::get_description() const {
  return description;
}

std::string BeverageType::get_serving_size() const {
  return serving_size;
}

int BeverageType::get_calories() const {
  return calories;
}

double BeverageType::get_price() const {
  return price;
}

std::string BeverageType::to_string() {
  std::string ret = "Name: " + name + "\ndescription" + description + "\nServing size: " + serving_size + "\nCalories: " + calories + '\n';
}
