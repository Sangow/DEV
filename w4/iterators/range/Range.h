#ifndef RANGE_H
#define RANGE_H

#include <iostream>

template<class Type>
class Range {
    private:
        Type first;
        Type last;
        Type current;
        int step;
        int currIndex;

    public:
        Range(Type min = 4, Type max = 42, int step = 2);
        
        void rewind();
        void next();
        void prev();

        void operator++(int);
        void operator--(int);

        Type value();
        Type begin();
        Type end();

        bool over();

        Type operator*();
        Type operator[](int indexNeeded);

        void changeIndex(int indexNeeded);

};

#endif // RANGE_H