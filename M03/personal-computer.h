#ifndef PERSONCOMPUTER_H
#define PERSONCOMPUTER_H
#include <string>

class personal_computer {
public:
  personal_computer();
  personal_computer(std::string, std::string, std::string, std::string,
                    int, std::string, int);
  
  std::string get_manufacturer() const;
  std::string get_form_factor() const;
  std::string get_serial_number() const;
  std::string get_processor() const;
  int get_ram() const;
  std::string get_storage_type() const;
  int get_storage_size() const;

  void set_ram(int);
  void set_storage_type(std::string);
  void set_storage_size(int);

  bool is_valid_int(std::string);
  bool validate_manufacturer(init_manufacturer);
  bool validate_form_factor(init_form_factor);
  bool validate_serial_number(init_serial_number);
  bool validate_processor(init_processor);
  bool validate_ram(init_ram);
  bool validate_storage_type(init_storage_type);
  bool validate_storage_size(init_storage_size);

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
