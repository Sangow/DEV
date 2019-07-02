#include "Countable.h"

Countable::Countable() {
    count += 1;
}

int Countable::getCount() {
    return count;
}

int Countable::count = 0;