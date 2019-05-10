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

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    return out << "Date: " << date.getDay() << "." << date.getMonth() << "." << date.getYear();
}