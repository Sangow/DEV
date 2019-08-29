#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"
#include "../state/HumanState.h"
#include "../weapon/Dagger.h"

class Rogue : public Unit {
    public:
        Rogue(char* charName);
        ~Rogue();
};

#endif // ROGUE_H