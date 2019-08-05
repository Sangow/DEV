#include "Fibonacci.h"
#include <cmath>

Fibonacci::Fibonacci(int seqNumber) {
    if ( std::abs(seqNumber) > MAX_LIMIT ) {
        throw OutOfMaxLimit();
    }

    this->number = seqNumber;

    if ( this->number == 0 ) {
        this->current = 0;
    } else if ( this->number < 0 ) {
        this->current = 1;
        this->first = 1;
        this->second = 0;
        this->negative = true;
        this->index = 1;
    } else {
        this->current = 1;
        this->first = 0;
        this->second = 1;
        this->negative = false;
        this->index = 1;
    }
};

void Fibonacci::next() {
    if ( this->negative ) {
        this->current = this->second - this->first;
        this->second = this->first;
        this->first = this->current;
    } else if ( !this->negative ) {
        this->current = this->first + this->second;
        this->first = this->second;
        this->second = this->current;
    }
    this->index += 1;
};

void Fibonacci::operator++(int) {
    this->next();
};

void Fibonacci::prev() {
    if ( this->negative ) {
        this->current = this->second;
        this->second = this->first + this->second;
        this->first = this->current;
    } else if ( !this->negative ) {
        this->current = this->first;
        this->first = this->second - this->first;
        this->second = this->current;
    }
    this->index -= 1;
};

void Fibonacci::operator--(int) {
    this->prev();
};

long long Fibonacci::operator*() {
    return this->current;
};

bool Fibonacci::isOver() {
    if ( this->index > std::abs(this->number) ) {
        this->prev();
        return true;
    }
    if ( this->index < 1 ) {
        this->next();
        return true;
    }
    return false;
};