#ifndef GEOM_PROG_H
#define GEOM_PROG_H

#include <iostream>
#include <cmath>

class OutOfRangeException {};

template <class Type>
class GeomProg {
    private:
        Type first;
        Type last;
        int step;
        Type current;
        int currIndex;
        int maxIndex;
    public:
        GeomProg(Type min = 4, int length = 15, Type step = 2);

        void rewind();

        void next();
        void operator++(int);

        Type value() const;
        Type begin() const;
        Type end() const;

        Type operator*() const;
        Type operator[](int index) const;
        void changeIndex(int index);

        bool over();
};

#endif // GEOM_PROG_H