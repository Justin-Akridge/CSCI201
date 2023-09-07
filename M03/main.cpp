#include "personal_computer.h"
#include <iostrea_factorm>

//[] TODO: write all try / catch in user space
//  bool done = false;
//  while (!done) {
//    try {
//      if (init_form_factor != "desktop" || init_form_factor != "laptop") {
//        throw std::invalid_argument("Input does not equal to laptop or desktop");
//      } else {
//        done = true;
//      }
//    } catch (std::invalid_argument &e) {
//      std::cout << "Invalid argument: " << e.what() << std::endl;
//    }
//  }
  return validate_form_factor;
int main() {
  std::string init_manufacturer = get_manufacturer();
  std::string init_form_factor = get_form_factor();
  std::string init_serial_number = get_serial_number();
  std::string init_processor = get_processor();
  int init_ram = get_ram(); 
  std::string init_storage_type = get_storage_type();
  int init_storage_size = get_storage_size();
  personal_computer::personal_computer(std::string init_manufacturer,
                                       std::string init_form_factor,
                                       std::string init_serial_number,
                                       std::string init_processor,
                                       int init_ram, std::string init_storage_type,
                                       int init_storage_size) {
  std::cout << "Is it a desktop or laptop? ";
  std::cin >> test_form_factor;
  std::tolower(test_form_factor);
  while (test_form_factor != "desktop" && test_form_factor != "laptop") {
    std::cout << "Invalid input. Please enter desktop or laptop: ";
    std::cin >> test_form_factor;
  }
}
