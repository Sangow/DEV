#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#define MAX_LIMIT 92

class OutOfMaxLimit {};

class Fibonacci {
    private:
        bool negative;
        int index;
        int number;
        long long current;
        long long first;
        long long second;
    public:
        Fibonacci(int seqNumber = 42);

        void next();
        void operator++(int);

        void prev();
        void operator--(int);

        long long operator*();

        bool isOver();

};

#endif // FIBONACCI_H