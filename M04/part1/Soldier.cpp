#include "Soldier.h"
#include <cassert>
double Soldier::get_pay() const {
  return pay;
}

std::string Soldier::get_name() const {
  return name;
}

std::string Soldier::get_rank() const {
  return rank;
}

void Soldier::set_pay(double init_pay) {
  assert(pay >= 0);
  pay = init_pay
}

void Soldier::set_name(std::string &init_name) {
  name = init_name;
}

void Soldier::set_rank(std::string &init_rank) {
  rank = init_rank;
}

std::string Soldier::to_string() {
  std::string s = name + " " + rank + " " + classification;
  return s;
}

bool operator==(const Soldier &obj) const {
  return (name == obj.name && rank == obj.rank && classification == obj.classification);
}

Soldier::Soldier() {
  name = "";
  rank = "";
  classification = ""; 
  pay = 0.0;
}

Soldier(std::string init_name, std::string init_rank, 
        std::string init_classification, double init_pay) {
  name = init_name;
  rank = init_rank;
  classification = init_classification;
  pay = init_pay;
}
