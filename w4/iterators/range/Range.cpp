#include "Range.h"

Range::Range(int min, int max, int step) {
    this->currIndex = 0;
    this->first = min;
    this->current = min;
    this->step = step;
    this->last = max - (max - min) % step;
};

void Range::rewind() {
    this->current = this->first;
}

void Range::next() {
    if ( this->over() ) {
        return;
    }
    this->current += this->step;
    this->currIndex += 1;
};

void Range::prev() {
    if ( this->over() ) {
        return;
    }
    this->current -= this->step;
    this->currIndex -= 1;
};

void Range::operator++(int) {
    this->next();
};

void Range::operator--(int) {
    this->prev();
}

int Range::value() {
    return this->current;
};

int Range::begin() {
    return this->first;
};

int Range::end() {
    return this->last;
};

bool Range::over() {
    if ( this->current > this->last ) {
        this->current = this->last;
        this->currIndex -= 1;
        return true;
    } else if ( this->current < this->first ) {
        this->current = this->first;
        this->currIndex += 1;
        return true;
    }
    return false;
};

int Range::operator*() {
    return this->value();
};

int Range::operator[](int indexNeeded) {
    if ( indexNeeded < this->currIndex ) { 
        return this->current - (this->currIndex - indexNeeded) * step;
    }
    return this->current + (indexNeeded - this->currIndex) * step;
};

void Range::changeIndex(int indexNeeded) {
    if ( indexNeeded > this->currIndex ) {
        this->current = this->current + (indexNeeded - this->currIndex) * this->step;
        this->currIndex = indexNeeded;
    } else {
        this->current = this->current - (this->currIndex - indexNeeded) * this->step;
        this->currIndex = indexNeeded;
    }
};