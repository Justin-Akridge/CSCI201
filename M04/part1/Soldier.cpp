#include "Soldier.h"
#include <cassert>
#include <string>
#include <iostream>

std::string Soldier::get_name() const {
  return name;
}

std::string Soldier::get_rank() const {
  return rank;
}

Soldier& Soldier::set_pay(std::string init_pay) {
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
  std::string s = "Name: " + name + '\n' + "Rank: " + rank + '\n' + "classification: " + classification + '\n' + "Pay: $" + pay + " a year\n";
  return s;
}

bool Soldier::operator==(const Soldier &soldier) const {
  return (name == soldier.name && rank == soldier.rank 
          && classification == soldier.classification);
}

//bool Soldier::operator<(const Soldier &soldier) const {
//  return (rank < soldier.rank);
//}

//bool Soldier::operator++(const Soldier &soldier) const {
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
        std::string init_classification, std::string init_pay) {
  name = init_name;
  rank = init_rank;
  classification = init_classification;
  pay = init_pay;
}
