#include "Factorial.h"

long long Factorial::result() {
    long long result = 1;

    for ( int mult = 2; mult <= this->number; mult++ ) {
            result *= mult;
        }

    return result;
}

Factorial::Factorial(int number) {
    if ( number < 0 ) {
        throw InvalidNumber();
    }

    this->number = number;
    this->multiplier = 2;
    this->current = 1;
    this->limit = this->result();
};

void Factorial::next() {
    this->current *= this->multiplier;
    this->multiplier += 1;
};

void Factorial::operator++(int) {
    this->next();
};

long long Factorial::value() {
    return this->current;
};

long long Factorial::operator*() {
    return this->value();
};

bool Factorial::over() {
    if ( this->current >= limit ) {
        return true;
    }
    return false;
}