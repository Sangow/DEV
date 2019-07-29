#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>

class Fibonacci {
    private:
        int current;
        int number;
        int first;
        int second;
        int* cache;
        bool over;
        int index;
    public:
        Fibonacci(int seqNumber = 42);

        void next();
        void operator++();

        void prev();
        void operator--();

        long long value();
        long long operator*();

        bool isOver();
};

#endif // FIBONACCI_H