#include "Passport.h"

int Passport::setPassNumber() {
    if (  ) {

    }
}

void Passport::setPassSerial() {

}

Passport::Passport(const std::string& name, const std::string& surname, 
                    int dayOfBirth, int monthOfBirth, int yearOfBirth ) {
    this->name = name;
    this->surname = surname;
    this->dayOfBirth = dayOfBirth;
    this->monthOfBirth = monthOfBirth;
    this->yearOfBirth = yearOfBirth;

    this->number = getPassNumber()
}