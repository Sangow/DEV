#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <cmath>

class Prime {
    private:
        int* cache;
        int cachedValuesQuantity;

        int number;
        int current;
        int index;



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