#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>

class Passport {
    private:
        char serial[2];
        int number;
        static char lastSerial[2];
        static int lastNumber;

        std::string name;
        std::string surname;
        int dayOfBirth;
        int monthOfBirth;
        int yearOfBirth;

        void setPassportNumber();
        void setPassportSerial(char serial[]);
    public:
        Passport(const std::string& name = "Unknown", const std::string& surname = "Unknown", int dayOfBirth = 1, int monthOfBirth = 1, int yearOfBirth = 1970 );
        void setSerial(char serial[]);
        void setNumber(int number);
}

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif // PASSPORT_H