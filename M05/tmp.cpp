#include <iostream>

int main() {
  enum roast_type {Light, Medium, Dark, French_Roast, Espresso};
  std::cout << roast_type[0];
}
