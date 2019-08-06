#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <cmath>

class InvalidValueException {};

class Prime {
    private:
        int* cache;
        int cacheIndex;
        int maxCacheIndex;


        int maxIndex;
        int current;
        int index;

        bool validRequiredValue(int value);
        void fillCache();

    public:
        Prime(int number = 42);

        void next();
        void operator++();

        void prev();
        void operator--();

        int value();
        int operator*();

        bool isOver();
};

#endif // PRIME_H