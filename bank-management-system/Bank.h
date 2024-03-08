#pragma once
#include <unordered_map>
#include <string>
#include <string_view>

class bank {
public:
  bank();
  bank(double&, double&);
  int login(std::string_view, std::string_view);
private:
  double balance;
  double credit_line;
  std::unordered_map<int, int> account;
};

