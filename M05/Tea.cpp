#include <iostream>
TeaType::TeaType() {
  type = "";
  hot = false;
  creamer = "";
  sweetener = "";
  lemon = false;
}

TeaType::TeaType(std::string init_type, bool init_hot, std::string init_creamer, 
                 std::string init_sweetener, bool init_lemon) : BeverageType( {


std::string TeaType::get_type() const {
  return type;
} 

bool TeaType::get_hot() {
  return hot;
}

std::string TeaType::get_creamer() {
  return creamer;
}

std::string TeaType::get_sweetener() {
  return sweetener;
}

bool TeaType::get_lemon() {
  return lemon;
}

std::string TeaType::to_string() {
  std::string s = 

  std::string type;
  bool hot;
  std::string creamer;
  std::string sweetener;
  bool lemon;
