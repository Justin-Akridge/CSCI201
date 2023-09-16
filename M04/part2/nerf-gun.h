#ifndef NERF_GUN_H
#define NERF_GUN_H
#include <string>

class Nerf_gun {
public:
  Nerf_gun();
  Nerf_gun(std::string, int, int);
  std::string get_model() const;
  int get_range() const;
  int get_capacity() const;
  int get_darts() const;
  void set_model(std::string);
  void set_range(int);
  void set_capacity(int);
  void set_darts(int); 
  bool operator==(const Nerf_gun &gun);
  bool operator<(const Nerf_gun &gun);
  Nerf_gun& operator--();
  Nerf_gun& operator+=(int);
  std::ostream operator<<(std::ostream&, const Nerf_gun &gun);
private:
  std::string model;
  int range;
  int capacity;
  int darts;
};

#endif
