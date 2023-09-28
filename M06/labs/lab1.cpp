#include <iostream>
class Abstract {
protected:
  int a = 50;
public:
  virtual void to_string() = 0;
  void print() {
    std::cout << "Printing in abstract: " << a << std::endl;
  }
};

class Real : public Abstract {
protected:
  int a = 40;
public:
  void to_string() {
    std::cout << "Print from real class: " << a << std::endl;
  }
};

int main() {
  Real *obj1 = new Real();
  obj1->to_string();
  obj1->print();

  Real *obj2 = new Real();
  obj1->to_string();
  obj1->print();
  
  delete obj1;
  delete obj2;
}
