#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <cstdio>
#include "Date.h"

class PassportException {
    public:
        std::string text;
        PassportException(const std::string& text) : text(text) {}
};

class Passport {
    private:
        int number;
        std::string serial;
        static int lastNumber;
        static std::string lastSerial;

        std::string name;
        std::string surname;
        int dayOfBirth;
        int monthOfBirth;
        int yearOfBirth;

        Date date;

        void validNextSN();
        static bool isUpperCaseSymbol(char symbol);
    public:
        Passport(const std::string& name = "Kon", const std::string& surname = "Cheniy", const Date& date = Date());
        ~Passport();
        static void setSN(const std::string& serial = "AA", int number = 1);
        const std::string getSerial() const;
        const std::string getNumber() const;
        const std::string& getName() const;
        const std::string& getSurname() const;
        const Date& getDate() const;
};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif // PASSPORT_H