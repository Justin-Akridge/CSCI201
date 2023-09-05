#ifndef PERSONCOMPUTER_H
#define PERSONCOMPUTER_H
#include <string>

class personal_computer {
public:
  personal_computer();

private:
  std::string manufacturer;
  std::string form_factor;
  std::string serial_number;
  std::string processor;
  int ram;
  std::string storage_type;
  int storage_size;
};
#endif
