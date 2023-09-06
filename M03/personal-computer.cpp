#include "personal-computer.h"
#include <iostream>

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


std::string personal_computer::get_manufacturer() const;
std::string personal_computer::get_form_factor() const;
std::string personal_computer::get_serial_number() const;
std::string personal_computer::get_processor() const;
int personal_computer::get_ram() const;
std::string personal_computer::get_storage_type() const;
int personal_computer::get_storage_size() const;
