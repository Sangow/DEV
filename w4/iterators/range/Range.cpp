#include "Range.h"

Range::Range(int min, int max, int step) {
    this->first = min;
    this->curr = min;
    this->step = step;
    this->last = max - (max - min) % step;
};

void Range::next() {
    int next = this->curr + this->step;
    if ( next <= this->last ) {
        this->curr = next;
    } else {
        throw Zalupa();
    }
};

void Range::prev() {
    int previous = this->curr - this->step;

    if ( previous >= this->last ) {
        this->curr = previous;
    } else {
        throw Zalupa();
    }
};

void Range::operator++(int) {
    this->next();
};

void Range::operator--(int) {
    this->prev();
}

int Range::value() {
    return this->curr;
};

int Range::begin() {
    return this->first;
};

int Range::end() {
    return this->last;
};

bool Range::operator<(int value) {
    return this->curr < value;
}

int Range::operator*() {
    return this->curr;
};