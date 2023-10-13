//============================================================================
// Name        : date.h
// Author      : Dylan Powers
//============================================================================

#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
public:
  Date(int month, int day, int year);
  Date();

  [[nodiscard]] int month() const;
  [[nodiscard]] int day() const;
  [[nodiscard]] int year() const;

  [[nodiscard]] std::string toString() const;

private:
  int _month;
  int _day;
  int _year;
};

bool earlier(Date d1, Date d2);

#endif
