#include <iostream>
#include "Date.h"

void Date::validate(int day, int month, int year) {
    bool isLeap = false;

    if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) {
        isLeap = true;
    }
    if ( day < 1 || day > 31 ) {
        throw InvalidDate("Day is invalid!");
    }
    if ( month < 1 || month > 12 ) {
        throw InvalidDate("Month is invalid!");
    }
    if ( month == 2 && day > 28 && !isLeap ) {
        throw InvalidDate("Invalid day in nonLeap February!");
    }
    if ( month == 2 && day > 29 && isLeap ) {
        throw InvalidDate("Invalid day in leap February!");
    }
    if ( ( month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30 ) {
        throw InvalidDate("Invalid day in 30Day month!");
    }
}

Date::Date(int day, int month, int year) {
    this->validate(day, month, year);

    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {}

const std::string Date::getDay() const {
    char result[3];

    sprintf(result, "%02d", this->day);
    return result;
}

const std::string Date::getMonth() const {
    char result[3];

    sprintf(result, "%02d", this->month);
    return result;
}

int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    return out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
}