#ifndef RANGE_H
#define RANGE_H

#include <iostream>

class Zalupa {};

class Range {
    private:
        int first;
        int last;
        int curr;
        int step;

    public:
        Range(int min = 4, int max = 42, int step = 2);
        
        void next();
        void prev();

        void operator++(int);
        void operator--(int);

        int value();
        int begin();
        int end();

        bool operator<(int value);

        int operator*();

};

#endif // RANGE_H