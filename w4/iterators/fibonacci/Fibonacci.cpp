#include "Fibonacci.h"

Fibonacci::Fibonacci(int seqNumber) : number(seqNumber) {

    if ( this->number == 0 ) {
        this->current = 0;
        this->over = true;
    }

    if ( this->number < 0 ) {
        this->current = 1;
        this->first = 1;
        this->second = 0;
        this->over = false;
        this->index = 0;
        cache = new int;
        cache[0] = this->current;
    } else {
        this->current = 1;
        this->first = 0;
        this->second = 1;
        this->over = false;
        this->index = 0;
        cache = new int;
        cache[0] = this->current;
    }
};

void Fibonacci::next() {
    if ( this->number < 0 && this->index < abs(this->number) ) {
        this->current = this->second - this->first;
        this->second = this->first;
        this->first = this->current;
        this->index += 1;
    } else if ( this->index < this->number ) {
        this->current = this->first - this->second;
        this->first = this->second;
        this->second = this->current;
        this->index += 1; 
    }
};

void Fibonacci::operator++(int) {
    this->next();
};

long long Fibonacci::value() {
    
};