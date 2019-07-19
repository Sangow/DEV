#ifndef GEOM_PROG_H
#define GEOM_PROG_H

#include <iostream>

class GeomProg {
    private:
        int first;
        int last;
        int step;
        int curr;
    public:
        GeomProg(int min = 4, int max = 42, int step = 2);

        void next();
        void prev();

        void operator++(int);
        void operator--(int);

        int value();
        int begin();
        int end();
};

#endif // GEOM_PEOG_H