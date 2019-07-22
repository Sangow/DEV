#ifndef RANGE_H
#define RANGE_H

#include <iostream>

class Range {
    private:
        int first;
        int last;
        int current;
        int step;
        int currIndex;

    public:
        Range(int min = 4, int max = 42, int step = 2);
        
        void rewind();
        void next();
        void prev();

        void operator++(int);
        void operator--(int);

        int value();
        int begin();
        int end();

        bool over();

        int operator*();
        int operator[](int indexNeeded);

        void changeIndex(int indexNeeded);

};

#endif // RANGE_H