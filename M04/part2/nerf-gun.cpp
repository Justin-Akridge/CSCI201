#include <iostream>
#include "nerf-gun.h"

Nerf_gun() {
  model = "";
  range = 0;
  capacity = 0;
  darts = 0;
}

Nerf_gun(std::string init_model, int init_range, int init_capacity) {
  model = init_model;
  range = init_range;
  capacity = init_capacity;
  darts = 30;
}

std::string get_model() const {
  return model;
}

int get_range() const {
  return range;
}

int get_capacity() const {
  return capacity;
}

int get_darts() const {
  return darts;
}

void set_model(std::string new_model) {
  model = new_model;
}

void set_range(int new_range) {
  range = new_range;
}

void set_capacity(int new_capacity) {
  capacity = new_capacity;
}

void set_darts(int new_dart_amount) {
  darts = new_dart_amount;
} 

bool operator==(const Nerf_gun &gun) const {
  return (darts == gun.darts);
}

bool operator<(const Nerf_gun &gun) const {
  return (darts < gun.darts);
}

Nerf_gun& operator--() const {
  try {
    if (darts - 1 <= 0) {
      darts = 0;
      throw std::out_of_range("You are out of ammo. You need to reload.");
    }
    --darts;
  } catch (std::out_of_range &e) {
    std::cerr << e.what() << '\n';
  }
}

Nerf_gun& operator+=() const;
//std::osstream operator<<(const Nerf_gun &gun) const;
int main() {
}

/*
 * std::string model;
 * int range;
 * int capacity;
 * int darts;
 */
