#include "Passport.h"

void Passport::validNextSN() {
    if ( lastNumber < 999999 ) {
        lastNumber += 1;
    } else if ( lastSerial[0] == 'Z' && lastSerial[1] == 'Z' ) {
        throw PassportException("Max passport amount was reached!");
    } else if ( lastSerial[1] == 'Z' ) {
        lastSerial[0] += 1;
        lastSerial[1] = 'A';
        lastNumber = 1;
    } else {
        lastSerial[1] += 1;
        lastNumber = 1;
    }
}

bool Passport::isUpperCaseSymbol(char symbol) {
    if ( symbol > 64 && symbol < 91 ) {
        return true;
    }
    return false;
}

Passport::Passport(const std::string& name, const std::string& surname, const Date& date) {
    validNextSN();
    this->serial = lastSerial;
    this->number = lastNumber;
    this->date = date;

    this->name = name;
    this->surname = surname;
};

Passport::~Passport() {
    std::cout << "dest!" << std::endl;
}

void Passport::setSN(const std::string& serial, int number) {
    if ( serial.length() > 2 ) {
        throw PassportException("Invalid serial size!");
    }
    if ( !isUpperCaseSymbol(serial[0]) || !isUpperCaseSymbol(serial[1]) ) {
        throw PassportException("Invalid serial format!");
    }
    if ( number < 1 || number > 999999 ) {
        throw PassportException("Number is out of range!");
    }
    lastSerial = serial;
    lastNumber = number - 1;
}

const std::string Passport::getSerial() const {
    char result[3];

    sprintf(result,"%c%c", this->serial[0], this->serial[1]);
    return result;
}

const std::string Passport::getNumber() const {
    char buffer[7];

    sprintf(buffer, "%06d", this->number);
    return buffer;
}

const std::string& Passport::getName() const {
    return this->name;
}

const std::string& Passport::getSurname() const {
    return this->surname;
}

const Date& Passport::getDate() const {
    return this->date;
}


std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << "Name:\t\t" << passport.getName() << std::endl;
    out << "Surname:\t" << passport.getSurname() << std::endl;
    out << "S/N:\t\t" << passport.getSerial() << " " << passport.getNumber() << std::endl;
    out << "Date of birth:\t" << passport.getDate();
    return out;
}

std::string Passport::lastSerial("AA");
int Passport::lastNumber = 0;