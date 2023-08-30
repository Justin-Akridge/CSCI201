#include <iostream>
#include <string>

class Date {
public:
  Date();
  Date(int, int, int);
  void setMonth();
  void setDay();
  void setYear();
  std::string getMonth();
  int getDay();
  int getYear();
  std::string date_to_string();
private:
  int month;
  int day;
  int year;
};

Date::Date() {}

std::string Date::date_to_string() {
  std::string str_day = std::to_string(day);
  std::string str_month = getMonth();
  std::string str_year = std::to_string(year);
  std::string date = str_month + " " + str_day + ", " + str_year;
  return date;
}

void Date::setMonth() {
  bool flag = false;
  do {
    try {
      std::cout << "Enter the month: ";
      std::string s_initMonth;
      std::cin >> s_initMonth;
      for (int i = 0; i < s_initMonth.size(); i++) {
        if (i == 0 && s_initMonth[i] == '-') {
          continue;
        }
        if (!isdigit(s_initMonth[i])) {
          throw s_initMonth;
        }
      }
      int i_initMonth = std::stoi(s_initMonth);
      if (i_initMonth < 1 || i_initMonth > 12) {
        throw i_initMonth;
      }
      month = i_initMonth;
      flag = true;
    } catch(int i_initMonth) {
      if (i_initMonth > 12)
        std::cout << "There are only 12 months in a year.\n"; 
      else
        std::cout << "A negative month is not a valid month.\n";
    } catch(std::string s_initMonth) {
      if (std::stoi(s_initMonth) > 12)
        std::cout << "There are only 12 months in a year.\n"; 
      else
        std::cout << "A negative month is not a valid month.\n";
    }
  } while(!flag);
}

void Date::setDay() {
  bool flag = false;
  do {
    try {
      std::cout << "Enter the day of the month: ";
      std::string s_initDay;
      std::cin >> s_initDay;
      for (int i = 0; i < s_initDay.size(); i++) {
        if (i == 0 && s_initDay[i] == '-') {
          continue;
        }
        if (!isdigit(s_initDay[i])) {
          throw std::stoi(s_initDay);
        }
      }
      int i_initDay = std::stoi(s_initDay);
      if (i_initDay < 0 || i_initDay > 31)
        throw i_initDay;
      switch(month) {
        case 2:
          if (i_initDay > 28)
            throw i_initDay;
        case 4:
        case 6:
        case 9:
        case 11:
          if (i_initDay > 30)
            throw i_initDay;
      }
      day = i_initDay;
      flag = true;
    } catch(int i_initDay) {
      switch(month) {
        case 2:
          std::cout << "There are only 28 day in February\n";
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          std::cout << "There are only 30 day in " << getMonth() << std::endl;
          break;
        default:
          std::cout << "There are only 31 days in " << getMonth() << std::endl;
          break;
      }
    }
  } while(!flag);
}

void Date::setYear() {
  bool flag = false;
  do {
    try {
      std::cout << "Enter the year: ";
      std::string s_initYear;
      std::cin >> s_initYear;
      for (int i = 0; i < s_initYear.size(); i++) {
        if (i == 0 && s_initYear[i] == '-') {
          continue;
        }
        if (!isdigit(s_initYear[i])) {
          throw s_initYear;
        }
      }
      int i_initYear = std::stoi(s_initYear);
      if (i_initYear < 1900 || i_initYear > 2020)
        throw i_initYear;
      year = i_initYear;
      flag = true;
    } catch(int i_initYear) {
      std::cout << i_initYear << " is an invalid year.\n";
    } catch(std::string s_initYear) {
      std::cout << s_initYear << " is an invalid year.\n";
    }
  } while(!flag);
}

std::string Date::getMonth() {
  std::string months[] = {"January", "Feburary" , "March", "April", "May", "June",
                          "July", "August", "September", "October", "November" , "December"};
  try {
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
        throw month;
        break;
    }   
  } catch (int month) {
      std::cout << "You still need to enter a month";
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
  Date d1;
  d1.setMonth();
  d1.setDay();
  d1.setYear();
  std::string year = d1.date_to_string();
  std::cout << year << std::endl;
}