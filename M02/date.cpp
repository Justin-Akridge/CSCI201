#include <iostream>
#include <string>

/*
 * Justin Akridge
 * 08/31/2023
 * This program takes a the month, day and year from the user. Validates the
 * data and then prints the date in a formatted manner
 * Date converter
 */

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
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter the month (1-12): ";
      std::string s_initMonth;
      std::cin >> s_initMonth;
      for (int i = 0; i < s_initMonth.size(); i++) {
        if (i == 0 && s_initMonth[i] == '-') {
          continue;
        }
        else if (!std::isdigit(s_initMonth[i])) {
          throw std::invalid_argument("input is not a number.");
        }
      }
      int i_initMonth = std::stoi(s_initMonth);
      if (i_initMonth < 1) {
        throw std::out_of_range("number must be greater then 0");
      } else if (i_initMonth > 12) {
        throw std::out_of_range("number must be less then 13");
      }
      month = i_initMonth;
      done = true;
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    } catch(std::out_of_range &e) {
      std::cerr << "Out of range: " << e.what() << "\n\n";
    }
  }
}

void Date::setDay() {
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter the day of the month: ";
      std::string s_initDay;
      std::cin >> s_initDay;
      for (int i = 0; i < s_initDay.size(); i++) {
        if (i == 0 && s_initDay[i] == '-') {
          continue;
        }
        if (!isdigit(s_initDay[i])) {
          throw std::invalid_argument("input is not a number.");
        }
      }
      int i_initDay = std::stoi(s_initDay);
      if (i_initDay < 0)
        throw std::invalid_argument("Input must be greater then 0.");
      switch(month) {
        case 2:
          if (i_initDay > 28)
            throw std::out_of_range("There are only 28 days in Feburary.");
        case 4:
        case 6:
        case 9:
        case 11:
          if (i_initDay > 30)
            throw std::out_of_range("There are only 30 days in ");
        default:
          if (i_initDay > 31)
            throw std::invalid_argument("There are only 31 days in ");
      }
      day = i_initDay;
      done = true;
    } catch(std::out_of_range &e) {
      switch(month) {
        case 2:
          std::cerr << "Out of range: " << e.what() << "\n\n";
          break;
        case 4:
        case 6:
        case 9:
        case 11:
          std::cout << "Out of range: " << e.what() << getMonth() << "\n\n";
          break;
        default:
          std::cout << "Out of range: " << e.what() << getMonth() << "\n\n";
          break;
      }
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
  }
}

void Date::setYear() {
  bool done = false;
  while (!done) {
    try {
      std::cout << "Enter the year: ";
      std::string s_initYear;
      std::cin >> s_initYear;
      for (int i = 0; i < s_initYear.size(); i++) {
        if (i == 0 && s_initYear[i] == '-') {
          continue;
        }
        if (!isdigit(s_initYear[i])) {
          throw std::invalid_argument("input is not a number.");
        }
      }
      int i_initYear = std::stoi(s_initYear);
      if (i_initYear < 1900)
        throw std::out_of_range("Year must be greater then 1900.");
      else if (i_initYear > 2020)
        throw std::out_of_range("Year must be less then 2020.");
      year = i_initYear;
      done = true;
    } catch(std::out_of_range &e) {
      std::cerr << "Out of range: " << e.what() << "\n\n";
    } catch(std::invalid_argument &e) {
      std::cerr << "Invalid argument: " << e.what() << "\n\n";
    }
  }
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
  std::cout << "Date is: " << year << std::endl;
}
