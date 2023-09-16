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
  void print();
  friend std::ostream& operator<< (std::ostream&, const Soldier&);
  bool operator==(const Soldier &) const;
  bool operator<(const Soldier&) const;
  Soldier operator--(int);
  Soldier operator--();
  Soldier operator++(int);
  Soldier operator++();
  Soldier();
  Soldier(int, std::string, std::string, std::string, std::string);
private:
  int rank_index;
  std::string name;
  std::string rank;
  std::string classification;
  std::string pay;
};

#endif
