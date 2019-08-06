#include "Prime.h"

bool Prime::validRequiredValue(int value) {
    return value > 0;
};

void Prime::fillCache() {

};

Prime::Prime(int number) {
    if ( !validRequiredValue(number) ) {
        throw InvalidValueException();
    }

    this->maxIndex = number;
    this->index = 1;

    this->maxCacheIndex = std::sqrt(this->maxIndex);
    this->cacheIndex = 1;
    this->cache = new int[this->maxCacheIndex];
};