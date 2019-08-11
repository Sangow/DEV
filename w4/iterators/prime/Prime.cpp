#include "Prime.h"

bool Prime::validRequiredValue(int value) {
    return value > 0;
};

bool Prime::isPrime(int x) {
    if ( x < 2 ) {
        return false;
    }
    for ( int i = 2; i * i <= x; i++ ) {
        if ( x % i == 0 ) {
            return false;
        }
    }
    return true;
};

void Prime::fillCache(int quantity) {
    int temp;
    int prime = this->current;

    for (int i = this->index; i < quantity; i++) {
        for ( temp = prime; this->isPrime(temp) == false; temp++ ) {
            prime = temp + 1;
        }
        prime += 1;
        this->cache[i] = temp;
    }
};

void Prime::resizeCache(int newCapacity) {
    int* newCache = (int*)realloc(this->cache, newCapacity * sizeof(int));

    if ( newCache == NULL ) {
        std::cout << "ZHOPA!" << std::endl;
    }

    this->cache = newCache;
    this->currCapacity = newCapacity;
};

Prime::Prime(int number) {
    if ( !validRequiredValue(number) ) {
        throw InvalidValueException();
    }

    this->index = 0;
    this->current = 2;
    this->maxCapacity = number;

    this->partCapacity = std::sqrt(this->maxCapacity);
    this->currCapacity = this->partCapacity;
    this->cache = new int[this->currCapacity];

    this->fillCache(this->partCapacity);

    this->over = false;
};

void Prime::next() {
    int newIndex = this->index + 1;

    if ( newIndex < this->currCapacity ) {
        this->index = newIndex;
        this->current = this->cache[this->index];
    } else if ( newIndex < this->maxCapacity ) {
        int newCapacity;

        if ( this->maxCapacity - this->currCapacity < this->partCapacity ) {
            newCapacity = this->maxCapacity;
        } else {
            newCapacity = this->currCapacity + this->partCapacity;
        }

        this->resizeCache(newCapacity);
        this->fillCache(this->currCapacity);

        this->index = newIndex;
        this->current = this->cache[this->index];
    } else {
        this->over = true;
    }
};

void Prime::operator++(int) {
    this->next();
};

void Prime::prev() {
    int newIndex = this->index - 1;

    if ( newIndex >= 0 ) {
        this->index = newIndex;
        this->current = this->cache[this->index];
    }
};

void Prime::operator--(int) {
    this->prev();
};

int Prime::value() {
    return this->current;
};

int Prime::operator*() {
    this->value();
};

bool Prime::isOver() {
    return over;
};