#include "personal-computer.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <limits>
//[]TODO FIGURE OUT A WAY TO GET THE USER INPUT AND VALIDATE IT INSIDE THE CONTRUCTOR
bool personal_computer::validate_manufacturer(std::string init_manufacturer) {
  bool done = false;
      for (int i = 0; i < manufacturer.size(); i++) {
        if (!std::isalpha(manufacturer[i])) {
          throw std::invalid_argument("Input is not a valid string");
        }
      }
  return manufacturer;
}
//write all validation functions here

std::string personal_computer::validate_form_factor(std::string init_form_factor) {
  bool done = false;
  while (!done) {
    try {
      if (init_form_factor != "desktop" || init_form_factor != "laptop") {
        throw std::invalid_argument("Input does not equal to laptop or desktop");
      } else {
        done = true;
      }
    } catch (std::invalid_argument &e) {
      std::cout << "Invalid argument: " << e.what() << std::endl;
    }
  }
  return validate_form_factor;
}

std::string personal_computer::validate_serial_number(std::string init_serial_number) {
  bool done = true;
  for (int i = 0; i < init_serial_number.size(); i++) {
    if (!is_alpha(init_serial_number[i]) || init_serial_number[i] != '-') {
      done = false;
    }
  }
  while (!done) {
    try {
      std::cout << "Enter Ano
    } catch (std::invalid_argument &e) {
      std::cout << e.what() << std::endl;
    }
  }
}

bool personal_computer::validate_processor(init_processor);
bool personal_computer::validate_ram(init_ram);
bool personal_computer::validate_storage_type(init_storage_type);
bool personal_computer::validate_storage_size(init_storage_size);

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
  manufacturer = validate_manufacturer(init_manufacturer);
  form_factor = validate_form_factor(init_form_factor);
  serial_number = validate_serial_number(init_serial_number);
  processor = validate_processor(init_processor);
  ram = validate_ram(init_ram);
  string storage_type = validate_storage_type(init_storage_type);
  storage_size = validate_storage_size(init_storage_size);
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

void personal_computer::set_ram(int ram_input) {
  ram = ram_input;
}

void personal_computer::set_storage_type(std::string storage_type_input) {
  storage_type = storage_type_input;
}

void personal_computer::set_storage_size(int storage_size_input) {
  storage_size = storage_size_input;
}
