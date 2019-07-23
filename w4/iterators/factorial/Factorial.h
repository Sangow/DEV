#ifndef FACTORAIL_H
#define FACTORAIL_H

#include <iostream>

class InvalidNumber {};
class OutOfRangeException {};

class Factorial{
    private:
        int number;
        long long current;
        int multiplier;
        long long limit;

        long long result(); 
    public:
        Factorial(int number = 5);

        void next();
        void operator++(int);
        // void prev();

        long long value();
        long long operator*();

        bool over();
};

#endif // FACTORIAL_H