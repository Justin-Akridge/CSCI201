#include "Soldier.h"
#include <vector>
#include <cassert>
#include <string>
#include <iostream>

std::string Soldier::get_name() const {
  return name;
}

std::string Soldier::get_rank() const {
  return rank;
}

void Soldier::set_pay(std::vector<std::string> &pay_scale, int rank_index) {
  pay = pay_scale[rank_index];
}

void Soldier::set_name(std::string &init_name) {
  name = init_name;
}

void Soldier::set_rank(std::string& init_rank) {
  rank = init_rank;
}

//void update_rank() {
//  set_pay
//}

std::string Soldier::to_string() {
  std::string s = "Name: " + name + '\n' + "Rank: " + rank + '\n' + "classification: " 
                  + classification + '\n' + "Pay: $" + pay + " a year\n";
  return s;
}

void Soldier::print() {
  std::cout << "Name: " + name + '\n' + "Rank: " + rank + '\n' + "classification: " 
                + classification + '\n' + "Pay: $" + pay + " a year\n";
}

int Soldier::get_rank_index() const {
  return rank_index;
}


bool Soldier::operator==(const Soldier &soldier) const {
  return (name == soldier.name && rank == soldier.rank 
          && classification == soldier.classification);
}

bool Soldier::operator<(const Soldier& soldier) const {
  return (rank_index < soldier.get_rank_index());
}

Soldier Soldier::operator++() {
  ++rank_index;
  return *this;
}

Soldier Soldier::operator++(int) {
  Soldier tmp(*this);
  ++rank_index;
  return tmp;
}

Soldier Soldier::operator--() {
  --rank_index;
  return *this;
}

Soldier Soldier::operator--(int) {
  Soldier tmp(*this);
  --rank_index;
  return tmp;
}

std::ostream& operator<< (std::ostream &os, const Soldier &soldier) {
  os << "Name: " << soldier.name << '\n' << "Rank: " << soldier.rank << '\n' << "classification: "
                 << soldier.classification << '\n' << "Pay: $" << soldier.pay << " a year\n";
  return os;
}

Soldier::Soldier() {
  rank_index = 0;
  name = "";
  rank = "";
  classification = ""; 
  pay = 0.0;
}

Soldier::Soldier(int init_rank_index, std::string init_name, std::string init_rank, 
        std::string init_classification, std::string init_pay) {
  rank_index = init_rank_index;
  name = init_name;
  rank = init_rank;
  classification = init_classification;
  pay = init_pay;
}
