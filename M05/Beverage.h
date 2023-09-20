#ifndef BEVERAGETYPE_H
#define BEVERAGETYPE_H 

#include <string>

class BeverageType {
public:
  BeverageType();
  BeverageType(std::string, std::string, serving_size, calories, price);
  std::string get_name() const;
  std::string get_description() const;
  std::string get_serving_size() const;
  int get_calories() const;
  double get_price() const; 
  std::string to_string();
private:
  std::string name;
  std::string description;
  int serving_size;
  int calories;
  double price;
};

#endif
