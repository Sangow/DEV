#include "Fibonacci.h"

long long Fibonacci::countLimit(int number) {
    long long x = 1;
    long long y = 1;

    if ( number == 0 ) {
        return 0;
    } else if ( number == -1 || number == 1 ) {
        return 1;
    } else if ( number > 1 ) {
        for ( int i = 2; i < number; i++ ) {
            y = x + y;
            x = y - x;
        }
        return y;
    } else {
        for ( int i = number; i <= 0; i++ ) {
            y = x - y;
            x = x - y;
        }
        return y;
    }
};

Fibonacci::Fibonacci(int seqNumber) {
    if ( abs(seqNumber) > MAX_LIMIT ) {
        throw OutOfMaxLimit();
    }

    this->number = seqNumber;
    this->limit = this->countLimit(this->number);

    if ( this->number == 0 ) {
        this->current = 0;
        this->over = true;
    } else if ( this->number < 0 ) {
        this->current = 1;
        this->first = 1;
        this->second = 0;
        this->over = false;
    } else {
        this->current = 1;
        this->first = 0;
        this->second = 1;
        this->over = false;
    }
};

void Fibonacci::next() {

};