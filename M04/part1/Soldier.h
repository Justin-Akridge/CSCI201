#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>

class Soldier {
public:
  int get_rank_index() const;
  std::string get_name() const;
  std::string get_rank() const;
  void set_rank_index();
  Soldier& set_pay(std::string);
  Soldier& set_name(std::string&);
  Soldier& set_rank(std::string&);
  std::string to_string();
  // std::ostream& operator<<(std::ostream& os, const Soldier &soldier) const; 
  bool operator==(const Soldier &soldier) const;
  bool operator<(const Soldier &soldier) const;
  Soldier operator--(const Soldier &soldier) const;
  Soldier operator++(const Soldier &soldier) const;
  Soldier();
  Soldier(std::string, std::string, std::string, std::string);
  //std::unordered_map
private:
  int rank_index;
  std::string name;
  std::string rank;
  std::string classification;
  std::string pay;
};

#endif
