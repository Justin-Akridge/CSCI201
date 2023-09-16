#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
#include <vector>

class Soldier {
public:
  int get_rank_index() const;
  std::string get_name() const;
  std::string get_rank() const;
  void set_rank_index();
  void update_rank();
  void set_pay(std::vector<std::string>&, int);
  void set_name(std::string&);
  void set_rank(std::string&);
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
