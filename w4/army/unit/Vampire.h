#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Unit.h"
#include "../state/VampireState.h"
#include "../weapon/Claws.h"

class Vampire : public Unit {
    public:
        Vampire(char* charName);
        ~Vampire();
};

#endif // VAMPIRE_H