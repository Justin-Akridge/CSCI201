#include "personal-computer.h"
#include <iostream>
#include <cctype>

personal_computer::personal_computer() {
  manufacturer = "";
  form_factor = "";
  serial_number = "";
  processor = "";
  ram = 0;
  string storage_type = "";
  storage_size = 0;
}

personal_computer::personal_computer(std::string init_manufacturer,
                                     std::string init_form_factor,
                                     std::string init_serial_number,
                                     std::string init_processor,
                                     int init_ram, std::string init_storage_type,
                                     int init_storage_size) {
  manufacturer = init_manufacturer;
  form_factor = init_form_factor;
  serial_number = init_serial_number;
  processor = init_processor;
  ram = init_ram;
  string storage_type = init_storage_type;
  storage_size = init_storage_size;
}

bool is_valid_int(std::string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!std::isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

std::string personal_computer::get_manufacturer() const {
  return manufacturer; 
}

std::string personal_computer::get_form_factor() const {
  return form_factor;
}

std::string personal_computer::get_serial_number() const {
  return serial_number;
}

std::string personal_computer::get_processor() const {
  return processor;
}

int personal_computer::get_ram() const {
  return ram;
}

std::string personal_computer::get_storage_type() const {
  return storage_type;
}

int personal_computer::get_storage_size() const {
  return storage_size;
}

void personal_computer::set_manufacturer(std::string manufacturer_input) {
  d::cin >> manufacturer;
}

void personal_computer::set_form_factor(std::string form_factor_input) {
  form_factor = form_factor_input;
}

void personal_computer::set_serial_number(std::string serial_number_input) {
  serial_number = serial_number_input;
}

void personal_computer::set_processor(std::string processor_input) {
  processor = processor_input; 
}

void personal_computer::set_ram(int ram_input) {
  ram = ram_input;
}

void personal_computer::set_storage_type(std::string storage_type_input) {
  storage_type = storage_type_input;
}

void personal_computer::set_storage_size(int storage_size_input) {
  storage_size = storage_size_input;
}
