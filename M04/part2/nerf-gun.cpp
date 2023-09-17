#include <iostream>
#include "nerf-gun.h"

Nerf_gun::Nerf_gun() {
  model = "";
  range = 0;
  capacity = 0;
  darts = 0;
}

Nerf_gun::Nerf_gun(std::string init_model, int init_range, int init_capacity) {
  model = init_model;
  range = init_range;
  capacity = init_capacity;
  darts = 30;
}

std::string Nerf_gun::get_model() const {
  return model;
}

int Nerf_gun::get_range() const {
  return range;
}

int Nerf_gun::get_capacity() const {
  return capacity;
}

int Nerf_gun::get_dart_count() const {
  return darts;
}

void Nerf_gun::set_model(std::string new_model) {
  model = new_model;
}

void Nerf_gun::set_range(int new_range) {
  range = new_range;
}

void Nerf_gun::set_capacity(int new_capacity) {
  capacity = new_capacity;
}

void Nerf_gun::set_darts(int new_dart_amount) {
  darts = new_dart_amount;
} 

bool Nerf_gun::operator==(const Nerf_gun &gun) {
  return (darts == gun.darts);
}

bool Nerf_gun::operator<(const Nerf_gun &gun) {
  return (darts < gun.darts);
}

Nerf_gun& Nerf_gun::operator--() {
  try {
    if (darts - 1 <= 0) {
      darts = 0;
      throw std::out_of_range("You are out of ammo. You need to reload.");
    }
    --darts;
    return *this;
  } catch (std::out_of_range &e) {
    std::cerr << e.what() << '\n';
  }
}

Nerf_gun& Nerf_gun::operator+=(int add_darts) {
  if (darts + add_darts > 30) {
    std::cout << "You can only load " << 30 - darts << " out of " << add_darts << '\n';
    darts = 30;
  } else {
    darts = add_darts; 
  }
  return *this;
}

std::ostream& operator<< (std::ostream& os, const Nerf_gun &gun) {
  os << "Model: " << gun.model << '\n' << "Range: " << gun.range << '\n' 
     << "Capacity:" << gun.capacity << '\n' << "Darts: " << gun.darts << '\n';
}

void Nerf_gun::fire() {
  if (darts - 1 <= 0) {
    darts = 0;
    std::cout << "Your are out of bullets. You need to reload.\n";
  } else {
    --darts;
  }
}
void Nerf_gun::reload() {
  darts = capacity;
}