#ifndef TEA_H
#define TEA_H

#include <string>

class TeaType : public BeverageType {
public:
  TeaType();
  TeaType(std::string, bool, std::string, std::string, bool);
  void set_type();
  void set_hot();
  void set_creamer();
  void set_sweetener();
  void set_lemon();
  std::string get_type();
  bool get_hot();
  std::string get_creamer();
  std::string get_sweetener();
  bool get_lemon();
  std::string to_string();
private:
  std::string type;
  bool hot;
  std::string creamer;
  std::string sweetener;
  bool lemon;
};

#endif
