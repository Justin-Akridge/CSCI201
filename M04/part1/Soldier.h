#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>

class Soldier {
public:
  double get_pay() const;
  std::string get_name() const;
  std::string get_rank() const;
  void set_pay(double);
  void set_name(std::string);
  void set_rank(std::string);
  std::string to_string();
  bool operator==(const Soldier &soldier) const;
  bool operator<(const Soldier &soldier) const;
  bool operator--(const Soldier &soldier) const;
  bool operator++(const Soldier &soldier) const;
  Soldier();
  Soldier(std::string, std::string, std::string, double);
private:
  std::string name;
  std::string rank;
  std::string classification;
  double pay;
};

#endif
