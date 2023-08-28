#include <iostream>
#include <exception>

class Date {
public:
  Date(int, int, int);
  void setMonth();
  void setDay();
  void setYear();
  std::string getMonth();
  int getDay();
  int getYear();
private:
  int month;
  int day;
  int year;
};

void Date::setMonth() {
  try {
    std::cout << "Enter the month: ";
    int initMonth;
    std::cin >> initMonth;
    if (initMonth < 1 || initMonth > 12) {
      throw initMonth;
    }
  } catch(int month) {
    std::cout << month << " is an invalid month.\n"; 
  }
}

void Date::setDay() {
  try {
    std::cout << "Enter the day of the month: ";
    int day;
    std::cin >> day;
    if (day < 0 || day > 31)
      throw day;
    switch(month) {
      case 2 :
        if (day > 28)
          throw day;
      case 4:
        if (day > 30)
          throw day;
      case 6:
        if (day > 30)
          throw day;
      case 9:
        if (day > 30)
          throw day;
      case 11:
        if (day > 30)
          throw day;
      default:
        day = day;
    }
  } catch(day) {
    std::cout << day << " is an invalid day of the month.\n";
  }
}

void Date::setYear() {
  try {
    std::cout << "Enter the year: ";
    int year;
    std::cin >> year;
    if (year < 1900 || year > 2020)
      throw year;
    year = year;
  } catch(year) {
    std::cout << year << " is an invalid year.\n"
}

std::string Date::getMonth() {
  std::string months = ["January", "Feburary" , "March", "April", "May", "June",
                        "July", "August", "September", "October", "November" , "December"];
  switch(month) {
    case 1:
      return months[0]; 
      break;
    case 2:
      return months[1]; 
      break;
    case 3:
      return months[2]; 
      break;
    case 4:
      return months[3]; 
      break;
    case 5:
      return months[4]; 
      break;
    case 6:
      return months[5]; 
      break;
    case 7:
      return months[6]; 
      break;
    case 8:
      return months[7]; 
      break;
    case 9:
      return months[8]; 
      break;
    case 10:
      return months[9]; 
      break;
    case 11:
      return months[10]; 
      break;
    case 12:
      return months[11]; 
      break;
    default:
      std::cout << "You need to still enter a date.\n"
      break;
  }
}

int Date::getDay() {
  return day;
}

int Date::getYear() {
  return year;
}

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

