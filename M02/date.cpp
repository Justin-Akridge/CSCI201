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
      std::string initMonth;
      std::cin >> initMonth;
      for (int i = 0; i < initMonth.size(); i++) {
        //[TODO] FINISH CHECKING THE INPUT FOR DIGITS IN ALL SETTERS
        if (!isdigit(initMonth[i])
      }
      if (initMonth < 1 || initMonth > 12) {
        throw initMonth;
      }
      month = initMonth;
      flag = true;
    } catch(int month) {
      std::cout << month << " is an invalid month.\n"; 
    } 
  } while(!flag);
}

void Date::setDay() {
  bool flag = false;
  do {
    try {
      std::cout << "Enter the day of the month: ";
      int initDay;
      std::cin >> initDay;
      if (initDay < 0 || initDay > 31)
        throw initDay;
      switch(month) {
        case 2:
          if (initDay > 28)
            throw initDay;
        case 4:
        case 6:
        case 9:
        case 11:
          if (initDay > 30)
            throw initDay;
      }
      day = initDay;
      flag = true;
    } catch(int initDay) {
      std::cout << initDay << " is an invalid day of the month\n";
    }
  } while(!flag);
}

void Date::setYear() {
  bool flag = false;
  do {
    try {
      std::cout << "Enter the year: ";
      int initYear;
      std::cin >> initYear;
      if (initYear < 1900 || initYear > 2020)
        throw initYear;
      year = initYear;
      flag = true;
    } catch(int initYear) {
      std::cout << initYear << " is an invalid year.\n";
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