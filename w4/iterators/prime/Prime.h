#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <cmath>

class InvalidValueException {};

class Prime {
    private:
        bool over;
        int partCapacity;
        
        int current;

        bool validRequiredValue(int value);
        bool isPrime(int number);
        void fillCache(int quantity);
        void resizeCache(int newCapacity);

    public:
        int* cache;
        int maxCapacity;
        int currCapacity;
        int index;
        Prime(int number = 42);
        // ~Prime();

        void next();
        void operator++(int);

        void prev();
        void operator--(int);

        int value();
        int operator*();

        bool isOver();
};

#endif // PRIME_H