#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <cmath>

class InvalidValueException {};

class Prime {
    private:
        bool over;

        int* cache;
        int partCapacity;
        int currCapacity;
        int maxCapacity;
        
        int index;
        int current;

        bool validRequiredValue(int value);
        bool isPrime(int number);
        void fillCache(int quantity);
        void resizeCache(int newCapacity);

    public:
        Prime(int number);
        ~Prime();

        void next();
        void operator++(int);

        void prev();
        void operator--(int);

        int value();
        int operator*();

        // Kostil`
        void resetOver();

        bool isOver();
};

#endif // PRIME_H