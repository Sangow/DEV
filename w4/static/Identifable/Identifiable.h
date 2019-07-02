#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <iostream>

class Identifiable {
    private:
        static int nextUID;
        int uID;
    public:
        Identifiable();
        static int getNextUID();
        int getUID() const;
};

#endif // IDENTIFIABLE_H