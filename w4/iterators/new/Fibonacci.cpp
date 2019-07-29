#include "Fibonacci.h"
#include <cmath>

Fibonacci::Fibonacci(int seqNumber) {
    if ( std::abs(seqNumber) > MAX_LIMIT ) {
        throw OutOfMaxLimit();
    }

    this->number = seqNumber;

    if ( this->number == 0 ) {
        this->current = 0;
        this->over = true;
    } else if ( this->number < 0 ) {
        this->current = 1;
        this->first = 1;
        this->second = 0;
        this->over = false;
        this->negative = true;
        this->index = 1;
    } else {
        this->current = 1;
        this->first = 0;
        this->second = 1;
        this->over = false;
        this->negative = false;
        this->index = 1;
    }
};

void Fibonacci::next() {
    if ( this->negative && this->index < std::abs(this->number) ) {
        this->current = this->second - this->first;
        this->second = this->first;
        this->first = this->current;
        this->index += 1;
    } else if ( this->index < this->number ) {
        this->current = this->first + this->second;
        this->first = this->second;
        this->second = this->current;
        this->index += 1;
    } else {
        this->over = true;
    }
};

void Fibonacci::operator++(int) {
    this->next();
};

void Fibonacci::prev() {
    if ( this->index == std::abs(this->number) ) {
        this->over = false;
    }

    if ( this->negative && this->index > std::abs(this->number) ) {

    } else if ( this->index == 1 ) {
        this->over = true;
        return;
    } else if ( this->index <= this->number ) {
        this->current = this->first;
        this->first = this->second - this->first;
        this->second = this->current;
        this->index -= 1;
    }
};

void Fibonacci::operator--(int) {
    this->prev();
};

long long Fibonacci::operator*() {
    return this->current;
};

bool Fibonacci::isOver() {
    return this->over;
};