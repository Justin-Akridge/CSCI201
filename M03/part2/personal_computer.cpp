#include "personal_computer.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <limits>

bool personal_computer::validate_manufacturer(std::string init_manufacturer) {
  for (int i = 0; i < init_manufacturer.size(); i++) {
    if (!std::isalpha(init_manufacturer[i])) {
      return false;
    }
  }
  return true;
}


bool personal_computer::validate_form_factor(std::string init_form_factor) {
  for (auto i : init_form_factor) {
    i = std::tolower(i);
  }
  if (init_form_factor != "desktop" && init_form_factor != "laptop) {
    return false;
  } else {
    return true;
  }
}

bool personal_computer::validate_serial_number(std::string init_serial_number) {
  for (int i = 0; i < init_serial_number.size(); i++) {
    if (!isalpha(init_serial_number[i]) && init_serial_number[i] != '-') {
      return false;
    }
  }
  return true;
}

bool personal_computer::validate_processor(std::string init_processor) {
  std::string processors[6] = {"i3", "i5", "i7", "ryzen3", "ryzen5", "ryzen7"};
  for (auto i : init_processor) {
    i = std::tolower(i);
  }
  for (int i = 0; i < processors.size(); i++) {
    if (init_processor == processors[i]) {
      return true;
    }
  } 
  return false;
}

bool personal_computer::validate_ram(int init_ram) {
  int ram_sizes[6] = {4, 6, 8, 16, 32, 64};
  for (int i = 0; i < ram_sizes.size(); i++) {
    if (init_ram == ram_sizes[i]) {
      return true;
    }
  }
  return false;
}

bool personal_computer::validate_storage_type(std::string init_storage_type) {
  std::string storage_types[4] = {"ssd", "hdd", "cd", "dvd"}; 
  for (auto i : init_storage_type) {
    i = std::tolower(i);
  }
  for (int i = 0; i < 4; i++) {
    if (init_storage_type == storage_types[i]) {
      return true;
    }
  }
  return false;
}

bool personal_computer::validate_storage_size(int init_storage_size) {
  int storage_sizes[5] = {128, 256, 512, 1, 2};
  for (int i = 0; i < 5; i++) {
    if (init_storage_size == storage_sizes[i]) {
      return true;
    }
  }
  return false;
}

personal_computer::personal_computer() {
  manufacturer = "";
  form_factor = "";
  serial_number = "";
  processor = "";
  ram = 0;
  std::string storage_type = "";
  storage_size = "";
}

personal_computer::personal_computer(std::string init_manufacturer,
                                     std::string init_form_factor,
                                     std::string init_serial_number,
                                     std::string init_processor,
                                     int init_ram, 
                                     std::string init_storage_type,
                                     std::string init_storage_size) {
  try {
    if (validate_manufacturer(init_manufacturer)) {
      manufacturer = init_manufacturer;
    } else {
      throw std::invalid_argument("input is not a valid manufacturer.");
    }
    if (validate_form_factor(init_form_factor)) {
      form_factor = init_form_factor;
    } else {
      throw std::invalid_argument("input is not a valid form factor.");
    }
    if (validate_serial_number(init_serial_number)) {
      serial_number = init_serial_number;
    } else {
      throw std::invalid_argument("input is not a valid serial number.");
    }
    if (validate_processor(init_processor)) {
      processor = init_processor;
    } else {
      throw std::invalid_argument("input is not a valid processor.");
    }
    if(validate_ram(init_ram)) {
      ram = init_ram;
    } else {
      throw std::invalid_argument("input is not valid amount of ram.");
    }
    if (validate_storage_type(init storage_type)) {
      storage_type = init_storage_type; 
    } else {
      throw std::invalid_argument("input is not valid a valid storage type.");
    }
    if (validate_storage_size(init_storage_size)) {
      storage_size = init_storage_size;
    } else {
      throw std::invalid_argument("input is not a valid storage size.");
    }
  } catch (std::invalid_argument &e) {
    std::cerr << "Invalid argument: " << e.what() << '\n';
  }
}

bool is_valid_int(std::string s) {
  for (int i = 0; i < s.size(); i++) {
    if (!std::isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

std::string personal_computer::to_string(personal_computer computer) {
  return "Manufacturer: " + computer.manufacturer + '\n' +
         "Form of computer: " + form_factor + '\n' +
         "Serial number: " + serial_number + '\n' +
         "Processor: " + processor + '\n' + 
         "Ram: " + ram + '\n' +
         "Storage type: " + storage_type + '\n' +
         "Storage size: " + storage_size + '\n';
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

std::string personal_computer::get_storage_size() const {
  return storage_size;
}

void personal_computer::set_ram(int ram_input) {
  ram = ram_input;
}

void personal_computer::set_storage_type(std::string storage_type_input) {
  storage_type = storage_type_input;
}

void personal_computer::set_storage_size(std::string storage_size_input) {
  storage_size = storage_size_input;
}

void personal_computer::print() {
  std::cout << "Manufacturer: " << get_manufacturer() << '\n';
  std::cout << "Form factor: " << get_form_factor() << '\n';
  std::cout << "Serial number: " << get_serial_number() << '\n';
  std::cout << "Processor: " << get_processor() << '\n';
  std::cout << "Ram: " << get_ram() << '\n';
  std::cout << "Storage type: " << get_storage_type() << '\n';
  std::cout << "Storage size: " << get_storage_size() << '\n';
}
