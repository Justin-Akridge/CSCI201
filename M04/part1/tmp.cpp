#include <iostream>

class add {
public:
  add();
  add(int a);
  add d();
  int x; 
};

add::add() {
  x = 0;
}

add::add(int a) {
  x = a;
}

add add::d() {
    x *= 2;
    return *this;
};

int main() {
  add s1(7);
  add s2;
  s2 = s1.d();
  std::cout << s2.x;
  std::cout << s1.x;
}
