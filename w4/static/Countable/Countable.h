#ifndef COUNTABLE_H
#define COUNTABLE_H

#include <iostream>

class Countable {
    private:
        static int count;
    public:
        Countable();
        static int getCount();
};

#endif // COUNTABLE_H