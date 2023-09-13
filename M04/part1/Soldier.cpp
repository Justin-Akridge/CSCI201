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

Soldier& Soldier::set_pay(double init_pay) {
  assert(pay >= 0);
  pay = init_pay;
  return *this;
}

Soldier& Soldier::set_name(std::string &init_name) {
  name = init_name;
  return *this;
}

Soldier& Soldier::set_rank(std::string &init_rank) {
  rank = init_rank;
  return *this;
}

std::string Soldier::to_string() {
  std::string s = name + " " + rank + " " + classification;
  return s;
}

bool Soldier::operator==(const Soldier &soldier) const {
  return (name == soldier.name && rank == soldier.rank 
          && classification == soldier.classification);
}

bool Soldier::operator<(const Soldier &soldier) const {
  return (rank < soldier.rank);
}

//bool Soldier::operator++<(const Soldier &soldier) const {
//  return soldier.rank++;
//  //check for rank: make sure they do not cross
//}
//
//bool Soldier::operator--(const Soldier &soldier) const {
//  return rank < soldier.rank--;
//  //check for rank: make sure they do not cross
//}
//
//std::ostream& operator<<(std::ostream& os, const Soldier &soldier) const {
//  os << soldier.name << " " << soldier.rank << " " << soldier.classification
//     << soldier.pay << '\n';
//}

Soldier::Soldier() {
  name = "";
  rank = "";
  classification = ""; 
  pay = 0.0;
}

Soldier::Soldier(std::string init_name, std::string init_rank, 
        std::string init_classification, double init_pay) {
  name = init_name;
  rank = init_rank;
  classification = init_classification;
  pay = init_pay;
}