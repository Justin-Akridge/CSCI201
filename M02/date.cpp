#include <iostream>

class Date {
public:
  Date(int, int, int);
private:
  int month;
  int day;
  int year;
};

Date::Date(int initMonth, int initDay, int initYear) {
  month = initMonth;
  day = initDay;
  year = initYear;
}

int main() {
  try {
    int month;
    std::cout << "Enter the month: ";
    std::cin >> month;
    if (month < 1 || month > 12)
      throw month
    int day;
    std::cout << "Enter the day: ";
    std::cin >> day;
    if (day < 1 || day  > 32)
      throw day;
    int year;
    std::cout << "Enter the year: ";
    std::cin >> year;
    if (year < 1900 || year > 2020)
      throw year;
  } catch (int value) {
    std::cout << value << " is out of range\n";
  }
}
